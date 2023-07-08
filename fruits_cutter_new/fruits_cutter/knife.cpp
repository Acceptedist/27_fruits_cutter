
#include "knife.h"

knife::knife()
{

}

knife::knife(QGraphicsView *_view, QGraphicsScene *_scene)
{
    view=_view;
    scene=_scene;

}
QRectF knife::boundingRect() const
{
    return QRectF(0,0,0,0);
}
void knife::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen mypen;                     //创建画笔
    mypen.setWidth(3);
    mypen.setColor(Qt::blue);
    mypen.setCapStyle(Qt::RoundCap);
    painter->setPen(mypen);            //画笔粗细
    // painter.setPen(QPen(QColor(147,255,243,800)));      //画笔颜色,目前为蓝色，可调（r,g,b,透明度）


    if(num>3)//把每一次鼠标移动的地方进行画点
    {
        for(int i=p.size()-3;i<p.size();++i)
        {
            painter->drawLine(p.at(i-1),p.at(i));

        }
    }//改变参数以设置拖尾长度

}

