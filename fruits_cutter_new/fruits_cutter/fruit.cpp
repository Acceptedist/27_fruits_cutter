
#include "fruit.h"

std::string real_fruits_names[]={"bomb","watermelon","apple","banana","peach","strawberry",
                                   "name1","name2","name3","name4","name5",
                                   "name6","name7","name8","name9","name10"};//储存所有水果的名字

fruit::fruit(QGraphicsView *_view,QGraphicsScene *_scene,int _NO,std::string _name, bool _fixed, bool _rotate,
             std::string _direction, double _x, double _y,
             double _v,double _a, double _w)
{  
    //QT相关设置
    //srand(time(0));
    view=_view;
    scene=_scene;
    setVisible(false);
    //标签设置
    NO=_NO;
    name=_name;
    if(name=="random")
        name=real_fruits_names[rand()%5+1];
    if(name=="bomb")
        fruit_pixmap.load(":/img/bomb.png");
    if(name=="watermelon")
        fruit_pixmap.load(":/img/watermelon.png");
    if(name=="apple")
        fruit_pixmap.load(":/img/apple.png");
    if(name=="banana")
        fruit_pixmap.load(":/img/banana.png");
    if(name=="peach")
        fruit_pixmap.load(":/img/peach.png");
    if(name=="strawberry")
        fruit_pixmap.load(":/img/strawberry.png");
    //运动状态设置
    fixed=_fixed;
    rotate=_rotate;
    direction=_direction;
    if(direction=="random")
        direction=((rand()%2)?"clockwise":"anticlockwise");
    x=_x;
    if(x<0)
        x=rand()%960;
    y=_y;
    if(y<0)
        y=800;
    v=_v;
    if(v<0)
        v=rand()%5+15;
    a=_a;
    if(a<0)
        a=(rand()%20+60.0+(x*40.0/960.0))*3.1415926/180.0;
    v_x=v*cos(a);
    v_y=v*sin(a);
    w=_w;
    if(w<0)
        w=(double)(rand()%20+20)/(double)(100);
    not_be_cutted=true;

    //每过20ms运行一次move_advance;
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_advance()));
    timer->start(20);

    //与view之间的关联函数
    connect(this,SIGNAL(del(int)),view,SLOT(del(int)));
    connect(this,SIGNAL(dehealth()),view,SLOT(Dehealth()));
    connect(this,SIGNAL(cut(std::string)),view,SLOT(cutcheck(std::string)));
}

fruit::~fruit()
{
    delete timer;
}

void fruit::fade(double second)
{
    second=0;
    emit del(NO);
}

void fruit::move_advance()
{
    //平移
    setPos(x,y);
    if(not_be_cutted)
        setVisible(true);
    if(!fixed)
    {
        x+=v_x;
        y-=v_y;
        v_y-=0.25;
    }
    //自转
    setTransformOriginPoint(fruit_pixmap.width()/2,
                            fruit_pixmap.height()/2);
    if(rotate)
    {
        if(direction=="clockwise")
            setRotation(rotation()+w*360/40);
        else if(direction=="anticlockwise")
            setRotation(rotation()-w*360/40);
    }
    //被切到检测
    if (QApplication::mouseButtons() & Qt::LeftButton)
    {
        QPoint globalPos = QCursor::pos();
        QPoint windowPos = view->mapFromGlobal(globalPos);
        double mouse_x = windowPos.x();
        double mouse_y = windowPos.y();
        if(mouse_x>x&&mouse_x<(x+fruit_pixmap.width())&&
            mouse_y>y&&mouse_y<(y+fruit_pixmap.height())&&not_be_cutted)
        {

            //生成两半水果
            fixed=true;
            not_be_cutted=false;
            emit cut(name);
            if(name!="bomb")//切到的不是炸弹
            {

                setVisible(false);
                std::string left_name;
                std::string right_name;
                if(name=="watermelon")
                {
                    left_name="watermelon_left";
                    right_name="watermelon_right";
                }
                if(name=="apple")
                {
                    left_name="apple_left";
                    right_name="apple_right";
                }
                if(name=="banana")
                {
                    left_name="banana_left";
                    right_name="banana_right";
                }
                if(name=="peach")
                {
                    left_name="peach_left";
                    right_name="peach_right";
                }
                if(name=="strawberry")
                {
                    left_name="strawberry_left";
                    right_name="strawberry_right";
                }
                cutted_fruit* fruit_left=new cutted_fruit(left_name,x,y,-1);
                cutted_fruit* fruit_right=new cutted_fruit(right_name,x,y,1);
                scene->addItem(fruit_left);
                scene->addItem(fruit_right);

                // 创建QTimer对象，3秒后触发singleShot信号
                QTimer* temp_timer = new QTimer(this);
                temp_timer->setSingleShot(true);
                temp_timer->start(3 * 1000);  // 设置时间单位为秒
                // 连接myFunction槽函数和singleShot信号，实现等待后执行操作
                connect(temp_timer, &QTimer::timeout, [=](){
                    // 此处执行需要等待之后的操作
                    scene->removeItem(fruit_left);
                    scene->removeItem(fruit_right);
                    delete fruit_left;
                    delete fruit_right;
                    timer->deleteLater();  // 记得释放QTimer对象
                    emit del(NO);
                });
            }
            else
            {
                for(int i=0;i<10;i++)
                {
                    setScale(scale()*1.1);
                    QTime dieTime = QTime::currentTime().addMSecs(100);//这个数字是等待t毫秒的意思
                    while( QTime::currentTime() < dieTime )
                        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                }
                setRotation(0);
                setPos(0,0);
                QSoundEffect *bombsound=new QSoundEffect(this);
                bombsound->setSource(QUrl("qrc:/bomb_sound.wav"));
                bombsound->setVolume(1.0f);
                bombsound->play();
                fruit_pixmap.load(":/img/bomb_flash.png");
                // 创建QTimer对象，3秒后触发singleShot信号
                QTimer* temp_timer = new QTimer(this);
                temp_timer->setSingleShot(true);
                temp_timer->start(1 * 1000);  // 设置时间单位为秒
                // 连接myFunction槽函数和singleShot信号，实现等待后执行操作
                connect(temp_timer, &QTimer::timeout, [=](){
                    // 此处执行需要等待之后的操作
                    setVisible(false);
                    qDebug()<<NO<<"\n";//测试内容
                    timer->deleteLater();  // 记得释放QTimer对象
                    emit del(NO);
                });
            }
        }
    }
    if(y>800)
    {
        if(name!="bomb")
            emit dehealth();
        emit del(NO);
    }

    return;
}

QRectF fruit::boundingRect() const
{
    return QRectF(0,0,fruit_pixmap.width(),fruit_pixmap.height());
}

void fruit::paint(QPainter* painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    painter->drawPixmap(0,0,fruit_pixmap);
}
