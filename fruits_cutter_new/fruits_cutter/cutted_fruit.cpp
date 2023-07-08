
#include "cutted_fruit.h"

cutted_fruit::cutted_fruit(std::string _name,double _x,double _y,int left_or_right)
{
    srand(time(0));
    setVisible(false);
    if(_name=="watermelon_left")
        fruit_pixmap.load(":/img/watermelon_left.png");
    if(_name=="watermelon_right")
        fruit_pixmap.load(":/img/watermelon_right.png");
    if(_name=="apple_left")
        fruit_pixmap.load(":/img/apple_left.png");
    if(_name=="apple_right")
        fruit_pixmap.load(":/img/apple_right.png");
    if(_name=="banana_left")
        fruit_pixmap.load(":/img/banana_left.png");
    if(_name=="banana_right")
        fruit_pixmap.load(":/img/banana_right.png");
    if(_name=="peach_left")
        fruit_pixmap.load(":/img/peach_left.png");
    if(_name=="peach_right")
        fruit_pixmap.load(":/img/peach_right.png");
    if(_name=="strawberry_left")
        fruit_pixmap.load(":/img/strawberry_left.png");
    if(_name=="strawberry_right")
        fruit_pixmap.load(":/img/strawberry_right.png");
    x=_x;
    y=_y;
    v_x=4*left_or_right;
    v_y=3;
    w=(rand()%20+20)/100.0;
    if(rand()%2==1)
        direction=true;
    else
        direction=false;

    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_advance()));
    timer->start(20);
}

cutted_fruit::~cutted_fruit()
{
    delete timer;
}

void cutted_fruit::move_advance()
{
    //平移
    setPos(x,y);
    setVisible(true);
    x+=v_x;
    y-=v_y;
    v_y-=0.25;
    //自转
    setTransformOriginPoint(fruit_pixmap.width()/2,
                            fruit_pixmap.height()/2);
    if(direction)
        setRotation(rotation()+w*360/40);
    else
        setRotation(rotation()-w*360/40);
}

QRectF cutted_fruit::boundingRect() const
{
    return QRectF(0,0,fruit_pixmap.width(),fruit_pixmap.height());
}

void cutted_fruit::paint(QPainter* painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    painter->drawPixmap(0,0,fruit_pixmap);
}
