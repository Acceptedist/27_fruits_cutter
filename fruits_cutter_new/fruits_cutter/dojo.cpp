
#include "dojo.h"

dojo::dojo(QWidget *parent)
    : QWidget{parent}
{
    //设置窗口标题、大小
    this->setFixedSize(960,720);
    this->setWindowTitle("fruits_cutter_dojo");
    //this->setWindowIcon(...);

    //设置背景
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/img/backboard.png")));
    this->setPalette(palette);

    //禁止鼠标穿透
    //this->setWindowModality(Qt::ApplicationModal);

    //去除边框
    this->setWindowOpacity(1);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setAttribute(Qt::WA_TranslucentBackground);

    //设置返回按钮
    this->backbutton=new QPushButton(this);
    this->backbutton->setIcon(QIcon(":/img/back.jpg"));
    this->backbutton->resize(QSize(46,46));
    this->backbutton->setIconSize(QSize(46,46));
    this->backbutton->move(20,20);

    //关联函数
    this->connect(this->backbutton,SIGNAL(clicked()),this,SLOT(backbuttonclick()));

    //读取文件
    std::ofstream out;
    out.open("dojo_data.txt",std::ios::app);
    out.close();
    std::ifstream in;
    in.open("dojo_data.txt");
    if(!in.is_open())
    {
        qDebug()<<"not open!!!!!!!!!!!!!!!!!!!!!!!";
    }
    QString data="排名         分数\n";
    for(int i=1;i<=9;i++)
    {
        data+=char('0'+i);
        data+="            ";
        char a[100];
        in.getline(a,100);
        data+=QString(a);
        data+="\n";
    }
    in.close();

    //文字内容
    this->label=new QLabel(this);
    label->resize(900,600);
    label->move(300,150);
    label->setText(data);
    label->show();
    label->setStyleSheet("QLabel{;color:white;}");
    label->setFont(QFont("宋体",30));
    label->setAlignment(Qt::AlignLeft);
}

void dojo::backbuttonclick()
{
    emit back();
}
