
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置窗口标题、大小
    this->setFixedSize(960,720);
    this->setWindowTitle("fruits_cutter");
    //this->setWindowIcon(...);

    //去除边框
    this->setWindowOpacity(1);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    //设置背景
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/img/backboard.png")));
    this->setPalette(palette);

    //设置开始按钮
    this->startbutton=new QPushButton(this);
    this->startbutton->setIcon(QIcon(":/img/start.png"));
    this->startbutton->resize(QSize(474,474));
    this->startbutton->setIconSize(QSize(474,474));
    this->startbutton->move(this->width()/2-this->startbutton->width()/2,this->height()/2-this->startbutton->height()/2);

//    m_player = new QMediaPlayer(this);
//    m_audioOutput = new QAudioOutput(this);
//    m_audioOutput->setVolume(50);

//    m_player->setAudioOutput(m_audioOutput);
//    m_player->setAudioOutput(m_audioOutput);
//    m_player->setSource(QUrl("D:\fruits_cutter\fruits_cutter\bgm.wav"));
//    //m_player->play();
//    this->connect(this->startbutton,SIGNAL(clicked()),m_player,SLOT(m_player->play()));

    this->connect(this->startbutton,SIGNAL(clicked()),this,SLOT(startbuttonclick()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startbuttonclick()
{
    this->menu=new mainmenu;
    this->menu->show();
    this->hide();

}

