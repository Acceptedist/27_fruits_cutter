#include "health.h"

health::health():hp(3),x(760),y(60)
{
}

health::health(QGraphicsView *_view,QGraphicsScene *_scene):hp(3),x(760),y(60)
{
    view=_view;
    scene=_scene;
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(paintEvent(QPaintEvent*event)));
    timer->start(20);

}

health::health(QGraphicsView *_view,QGraphicsScene *_scene,double x1,double y1):hp(3),x(x1),y(y1)
{
    view=_view;
    scene=_scene;
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(paint()));
    timer->start(20);

}

QRectF health::boundingRect() const
{
    return QRectF(40,0,760,60);
}

void health::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget)
{
    QPen mypen;
    mypen.setColor(Qt::white);//字体颜色，觉得丑可以改
    painter->setPen(mypen);
    QFont font1("KaiTi",20);//字体以及大小，同上
    painter->setFont(font1);
    painter->drawText(x,y,"生命：");
    painter->drawText(x+80,y,QString::number(hp));
    //hp--;监测点
    update();

}

void health::checkhealth(std::string name)
{
    if(name[1]=='o')
        hp=0;
    if(hp==0)
        //{
        emit zero();//信号
    //}
}

void health::dehealth()
{
    if(hp>0)
        hp--;

    if(hp==0)
    {
        emit zero();//信号
    }
}

int health::gethealth()
{
    return hp;
}
