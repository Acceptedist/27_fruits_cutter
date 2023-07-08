
#ifndef CUTTED_FRUIT_H
#define CUTTED_FRUIT_H

#include<QObject>
#include<QGraphicsItem>
#include<QPixmap>
#include<QTimer>
#include<QPainter>
#include<QSoundEffect>

class cutted_fruit:public QObject,public QGraphicsItem
{
    Q_OBJECT

private:
    QPixmap fruit_pixmap;
    QTimer *timer;
    double x,y;
    double v,v_x,v_y,w;
    bool direction;
public:
    cutted_fruit(std::string _name,double _x,double _y,int left_or_right);
    ~cutted_fruit();

public slots:
    //每过100ms的运动
    void move_advance();

public:
    virtual QRectF boundingRect() const;
    void paint(QPainter* painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
};

#endif // CUTTED_FRUIT_H
