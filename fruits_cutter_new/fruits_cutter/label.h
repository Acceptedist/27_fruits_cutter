
#ifndef LABEL_H
#define LABEL_H

#include<QObject>
#include<QWidget>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<QPixmap>
#include<string>

class label:public QGraphicsItem
{
public:
    label(std::string name,int x,int y);
    QPixmap label_pixmap;
public:
    virtual QRectF boundingRect() const;
    void paint(QPainter* painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
};

#endif // LABEL_H
