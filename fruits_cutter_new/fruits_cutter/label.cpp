
#include "label.h"

label::label(std::string name,int x,int y)
{
    if(name=="newgame")
    {
        label_pixmap.load(":/img/newgame.png");
        setPos(x,y);
    }
    else if(name=="quit")
    {
        label_pixmap.load(":/img/quit.png");
        setPos(x,y);
    }
    else if(name=="dojo")
    {
        label_pixmap.load(":/img/dojo.png");
        setPos(x,y);
    }
}

QRectF label::boundingRect() const
{
    return QRectF(0,0,label_pixmap.width(),label_pixmap.height());
}

void label::paint(QPainter* painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    painter->drawPixmap(0,0,label_pixmap);
}
