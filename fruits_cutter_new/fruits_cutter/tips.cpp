
#include "tips.h"

tips::tips(QWidget *parent)
    : QWidget{parent}
{
    //设置窗口标题、大小
    this->setFixedSize(960,720);
    this->setWindowTitle("fruits_cutter_dojo");
    //this->setWindowIcon(...);

    //去除边框
    this->setWindowOpacity(1);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setAttribute(Qt::WA_TranslucentBackground);

    //禁止鼠标穿透
    //this->setWindowModality(Qt::ApplicationModal);

    //设置背景
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/img/backboard.png")));
    this->setPalette(palette);

    //设置返回按钮
    this->backbutton=new QPushButton(this);
    this->backbutton->setIcon(QIcon(":/img/back.jpg"));
    this->backbutton->resize(QSize(46,46));
    this->backbutton->setIconSize(QSize(46,46));
    this->backbutton->move(20,20);

    //关联函数
    this->connect(this->backbutton,SIGNAL(clicked()),this,SLOT(backbuttonclick()));

    //文字内容
    this->label=new QLabel(this);
    label->resize(800,300);
    label->move(60,110);
    label->setText("水果切割者\n\n声明：\n\n本游戏模仿著名游戏水果忍者制作，不用于商业用途。");
    label->show();
    label->setStyleSheet("QLabel{;color:white;}");
    label->setFont(QFont("楷体",20));
    label->setAlignment(Qt::AlignCenter);
}

void tips::backbuttonclick()
{
    emit back();
}

