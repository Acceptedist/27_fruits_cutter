
#include "classic.h"

classic::classic()
{
    //随机数种子
    srand(time(0));

    //设置窗口标题、大小
    this->setFixedSize(960,720);
    this->setWindowTitle("fruits_cutter");
    //this->setWindowIcon(...);

    //禁止鼠标穿透
    this->setWindowModality(Qt::ApplicationModal);

    //去除边框
    this->setWindowOpacity(1);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    //设置背景
    this->setBackgroundBrush(QBrush(QPixmap(":/img/backboard.png")));
    this->scene=new QGraphicsScene;
    scene->setSceneRect(0,0,this->width()-2,this->height()-2);
    this->setScene(scene);
    scene->update();

    //加入刀
    this->kni=new knife;
    scene->addItem(kni);

   //加入生命值
    this->hea=new health;
    scene->addItem(hea);
    connect(this,SIGNAL(dehealth()),this->hea,SLOT(dehealth()));
    connect(this,SIGNAL(check(std::string)),this->hea,SLOT(checkhealth(std::string)));
    connect(this->hea,SIGNAL(zero()),this,SLOT(endgame()));


    //加入计分器
    this->sco=new score;
    scene->addItem(sco);
    connect(this,SIGNAL(check(std::string)),this->sco,SLOT(checkscore(std::string)));

    //不断产生水果的代码
    born_timer=new QTimer;
    connect(born_timer,SIGNAL(timeout()),this,SLOT(born()));
    born_timer->start(800);

    //不断产生炸弹的代码
    bomb_born_timer=new QTimer;
    connect(bomb_born_timer,SIGNAL(timeout()),this,SLOT(bomb_born()));
    bomb_born_timer->start(2000);

    point_timer=new QTimer;
    connect(point_timer,SIGNAL(timeout()),this,SLOT(getpoint()));
    point_timer->start(20);

}

classic::~classic()
{
    ;
}

void classic::born()//产生水果
{

    if(eog)
        goto labelend;
    all_fruits[num]=new fruit(this,this->scene,num);
    all_fruits[num]->setPos(0,0);
    scene->addItem(all_fruits[num]);
    ++num;
labelend:;
}

void classic::bomb_born()//产生炸弹
{

    if(eog)
        goto labelend;
    all_fruits[num]=new fruit(this,this->scene,num,"bomb");
    all_fruits[num]->setPos(0,0);
    scene->addItem(all_fruits[num]);
    ++num;
labelend:;
}

void classic::del(int NO)//删除
{
    delete this->all_fruits[NO];
}

void classic::Dehealth()//降低生命值（中转）
{
    emit this->dehealth();
    this->hea->update();
    this->scene->update();
    this->update();
}

void classic::cutcheck(std::string name)//fruit被切割后检查hea和sco
{
    emit this->check(name);
}

void classic::endgame()//游戏结束
{
    this->hea->update();
    this->scene->update();
    this->update();

    eog=true;

    //更新道场
    //update_dojo();

    // 创建QTimer对象，3秒后触发singleShot信号
    QTimer* temp_timer = new QTimer(this);
    temp_timer->setSingleShot(true);
    temp_timer->start(3 * 1000);  // 设置时间单位为秒
    // 连接myFunction槽函数和singleShot信号，实现等待后执行操作
    connect(temp_timer, &QTimer::timeout, [=](){
        // 此处执行需要等待之后的操作

        QGraphicsTextItem *txtitem = new QGraphicsTextItem(QString("最终得分：")+QString::number(sco->getscore()));
        txtitem->setPos(QPointF(300, 300));//设置要放置的的位置
        QFont font = txtitem->font(); // 获取原有的字体
        font.setPointSize(40); // 修改字体大小
        font.setFamily("楷体");
        font.setBold(true);//加粗
        txtitem->setFont(font); // 设置新的字体
        txtitem->setDefaultTextColor("white");//颜色：白
        scene->addItem(txtitem);//添加item到scene上

        // 创建QTimer对象，3秒后触发singleShot信号
        QTimer* temp_timer2 = new QTimer(this);
        temp_timer2->setSingleShot(true);
        temp_timer2->start(3 * 1000);  // 设置时间单位为秒
        // 连接myFunction槽函数和singleShot信号，实现等待后执行操作
        connect(temp_timer2, &QTimer::timeout, [=](){
            // 此处执行需要等待之后的操作
            //更新道场
            update_dojo();
            emit end();
        });
    });
}

void classic::getpoint()
{
    if(QApplication::mouseButtons() & Qt::LeftButton)
    {

        if(this->press)     //只有鼠标被按下的时候才记录坐标
        {
            QPoint globalPos = QCursor::pos();
            QPoint windowPos = this->mapFromGlobal(globalPos);
            point = windowPos;       //记录坐标
            p.append(point);
            //记录每一次移动的坐标
            QPainter *painter=new QPainter;
            QPen mypen;                     //创建画笔
            mypen.setWidth(3);
            mypen.setColor(Qt::white);
            mypen.setCapStyle(Qt::RoundCap);
            painter->setPen(mypen);            //画笔粗细
            // painter.setPen(QPen(QColor(147,255,243,800)));      //画笔颜色,目前为蓝色，可调（r,g,b,透明度）


            if(p.size()>1)
            {
                QGraphicsLineItem *line=new QGraphicsLineItem;
                line->setLine(QLineF(p.at(p.size()-1),p.at(p.size()-2)));
                line->setPen(mypen);
                line->setFlag(QGraphicsItem::ItemIsMovable);
                linelist.append(line);

            }
            if(linelist.size()>3)
            {
                for(int i=linelist.size()-3;i<linelist.size();i++)
                {
                    scene->addItem(linelist[i]);
                }
                for(int i=0;i<linelist.size()-3;i++)
                {
                    //scene->removeItem(linelist[i]);
                    if(linelist[i]!=NULL)
                    {
                        delete linelist[i];
                        linelist[i]=NULL;
                    }
                }
            }
            update();               //更新，让画笔画画
        }

    }






   //改变参数以设置拖尾长度

}

//更新排行榜
void classic::update_dojo()
{
    std::ofstream create;
    create.open("dojo_data.txt",std::ios::app);
    create.close();
    std::ifstream in;
    in.open("dojo_data.txt");
    if(!in.is_open())
    {
        qDebug()<<"not open!!!!!!!!!!!!!!!!";
    }
    int A[10]={0,0,0,0,0,0,0,0,0,0};
    A[0]=sco->getscore();
    for(int i=1;i<=9;i++)
    {
        in>>A[i];
    }
    std::sort(A,A+10,std::greater<int>());
    in.close();
    std::ofstream out;
    out.open("dojo_data.txt");
    for(int i=0;i<9;i++)
    {
        if(A[i]!=0)
            out<<A[i]<<"\n";
    }
    out.close();
}
