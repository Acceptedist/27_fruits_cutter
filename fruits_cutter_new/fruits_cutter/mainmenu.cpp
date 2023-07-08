
#include "mainmenu.h"
#include "qaudiooutput.h"

mainmenu::mainmenu()
{
    //设置窗口标题、大小
    this->setFixedSize(960,720);
    this->setWindowTitle("fruits_cutter");
    //this->setWindowIcon(...);

    //禁止鼠标穿透
    //this->setWindowModality(Qt::ApplicationModal);

    //去除边框
    this->setWindowOpacity(1);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setAttribute(Qt::WA_TranslucentBackground);

    //设置背景
    this->setBackgroundBrush(QBrush(QPixmap(":/img/backboard.png")));
    this->scene=new QGraphicsScene;
    scene->setSceneRect(0,0,this->width()-2,this->height()-2);
    this->setScene(scene);

    //添加开始游戏、退出游戏标签
    newgame=new label("newgame",270,190);
    scene->addItem(newgame);
    quit=new label("quit",610,450);
    scene->addItem(quit);
    ldojo=new label("dojo",190,450);
    scene->addItem(ldojo);

    //测试内容，直接产生一个游戏窗口
    //this->classicgame=new classic;
    //this->classicgame->show();
    //this->hide();

    //加入刀
    kni=new knife(this,scene);
    scene->addItem(kni);

   //开始游戏按钮
    startclassic=new fruit(this,scene,10001,"watermelon",true,true,"clockwise",320,240);
    connect(this->startclassic,SIGNAL(cut(std::string)),this,SLOT(cutslot(std::string)));
    startclassic->setPos(0,0);
    scene->addItem(startclassic);
    //退出游戏按钮
    exit=new fruit(this,scene,10002,"apple",true,true,"anticlockwise",640,480);
    connect(this->exit,SIGNAL(cut(std::string)),this,SLOT(cutslot(std::string)));
    exit->setPos(0,0);
    scene->addItem(exit);
    //排行榜按钮
    opendojo=new fruit(this,scene,10003,"banana",true,true,"anticlockwise",210,490);
    connect(this->opendojo,SIGNAL(cut(std::string)),this,SLOT(cutslot(std::string)));
    opendojo->setPos(0,0);
    scene->addItem(opendojo);

    //帮助按钮
    this->helpbutton=new QPushButton(this);
    this->helpbutton->setIcon(QIcon(":/img/wenhao.png"));
    this->helpbutton->resize(QSize(64,64));
    this->helpbutton->setIconSize(QSize(64,64));
    this->helpbutton->move(800,660);
    this->helpbutton->setFlat(true);
    this->connect(this->helpbutton,SIGNAL(clicked()),this,SLOT(helpbuttonclick()));

    //提示按钮
    this->tipsbutton=new QPushButton(this);
    this->tipsbutton->setIcon(QIcon(":/img/tanhao.png"));
    this->tipsbutton->resize(QSize(64,64));
    this->tipsbutton->setIconSize(QSize(64,64));
    this->tipsbutton->move(860,660);
    this->tipsbutton->setFlat(true);
    this->connect(this->tipsbutton,SIGNAL(clicked()),this,SLOT(tipsbuttonclick()));

    //音乐按钮
    this->musicbutton=new QPushButton(this);
    this->musicbutton->setIcon(QIcon(":/img/yinyuekai.png"));
    this->musicbutton->resize(QSize(64,64));
    this->musicbutton->setIconSize(QSize(64,64));
    this->musicbutton->move(860,60);
    this->musicbutton->setFlat(true);
    this->connect(this->musicbutton,SIGNAL(clicked()),this,SLOT(musicbuttonclick()));

    //加入bgm
    m_player=new QMediaPlayer;
    QAudioOutput *m_audioOutput=new QAudioOutput(this);
    m_player->setAudioOutput(m_audioOutput);
    m_player->setSource(QUrl("qrc:/bgm.wav"));
    m_player->setLoops(-1);
    m_player->play();


//    sound=new QSoundEffect(this);
//    sound->setSource(QUrl("qrc:/bgm.wav"));
//    sound->setVolume(50);
//    sound->setLoopCount(QSoundEffect::Infinite);
//    sound->play();

}

void mainmenu::cutslot(std::string name)//某个按钮被按下
{
    if(name=="watermelon")//开始游戏
    {
        if(!playing)
        {
            classicgame=new classic;
            classicgame->show();
            this->hide();
            playing=true;
            connect(this->classicgame,SIGNAL(end()),this,SLOT(reset()));
            _startclassic=false;
        }
        else
        {
            startclassic=new fruit(this,scene,10001,"watermelon",true,true,"clockwise",320,240);
            connect(this->startclassic,SIGNAL(cut(std::string)),this,SLOT(cutslot(std::string)));
            startclassic->setPos(0,0);
            scene->addItem(startclassic);
        }
    }
    else if(name=="apple")//退出游戏
    {
        if(!playing)
        {
            QApplication* app;
            app->exit(0);
            _exit=false;
        }
        else
        {
            exit=new fruit(this,scene,10002,"apple",true,true,"anticlockwise",640,480);
            connect(this->exit,SIGNAL(cut(std::string)),this,SLOT(cutslot(std::string)));
            exit->setPos(0,0);
            scene->addItem(exit);
        }
    }
    else if(name=="banana")//排行榜
    {
        if(!playing)
        {
            thedojo=new dojo;
            thedojo->show();
            this->hide();
            playing=true;
            connect(this->thedojo,SIGNAL(back()),this,SLOT(reset()));
            _opendojo=false;
        }
        else
        {
            opendojo=new fruit(this,scene,10003,"banana",true,true,"anticlockwise",210,490);
            connect(this->opendojo,SIGNAL(cut(std::string)),this,SLOT(cutslot(std::string)));
            opendojo->setPos(0,0);
            scene->addItem(opendojo);
        }
    }
}

mainmenu::~mainmenu()
{
    delete this->startclassic;
    delete this->exit;
    delete this->thedojo;
}

void mainmenu::delclassic()//游戏结束，删除游戏窗口
{
    delete classicgame;
    classicgame=NULL;
}

void mainmenu::del(int NO)//删除
{
}

void mainmenu::Dehealth()//降低生命值（中转）
{
}

void mainmenu::cutcheck(std::string name)//fruit被切割后检查hea和sco
{
}

void mainmenu::helpbuttonclick()//帮助按钮被点击
{
    if(playing)
        goto endlabel;
    playing=true;
    this->thehelp=new help();
    thehelp->show();
    this->hide();
    connect(this->thehelp,SIGNAL(back()),this,SLOT(reset()));
    _help=false;

endlabel:;
}

void mainmenu::tipsbuttonclick()//提示按钮被点击
{
    if(playing)
        goto endlabel;
    playing=true;
    this->thetips=new tips();
    thetips->show();
    this->hide();
    connect(this->thetips,SIGNAL(back()),this,SLOT(reset()));
    _tips=false;

endlabel:;
}

void mainmenu::musicbuttonclick()//音乐按钮被点击
{
    if(musicstate)
    {
        this->musicbutton->setIcon(QIcon(":/img/yinyueguan.png"));
        m_player->stop();
        musicstate=false;
    }
    else
    {
        this->musicbutton->setIcon(QIcon(":/img/yinyuekai.png"));
        m_player->play();
        musicstate=true;
    }


}

void mainmenu::reset()//重置mainmenu状态
{
    playing=false;
    if(!_startclassic)//重置按钮
    {
        delete classicgame;
        startclassic=new fruit(this,scene,10001,"watermelon",true,true,"clockwise",320,240);
        connect(this->startclassic,SIGNAL(cut(std::string)),this,SLOT(cutslot(std::string)));
        startclassic->setPos(0,0);
        scene->addItem(startclassic);
        _startclassic=true;
    }
    if(!_exit)//重置按钮
    {
        exit=new fruit(this,scene,10002,"apple",true,true,"anticlockwise",640,480);
        connect(this->exit,SIGNAL(cut(std::string)),this,SLOT(cutslot(std::string)));
        exit->setPos(0,0);
        scene->addItem(exit);
        _exit=true;
    }
    if(!_opendojo)//重置按钮
    {
        delete thedojo;
        opendojo=new fruit(this,scene,10003,"banana",true,true,"anticlockwise",210,490);
        connect(this->opendojo,SIGNAL(cut(std::string)),this,SLOT(cutslot(std::string)));
        opendojo->setPos(0,0);
        scene->addItem(opendojo);
        _opendojo=true;
    }
    if(!_help)//重置
    {
        delete thehelp;
        _help=true;
    }
    if(!_tips)//重置
    {
        delete thetips;
        _tips=true;
    }
    this->show();

    QEventLoop eventloop;//无限暂停（不知道为什么，删掉就崩溃）
    QTimer::singleShot(999999000, &eventloop, SLOT(quit()));
    eventloop.exec();
}
