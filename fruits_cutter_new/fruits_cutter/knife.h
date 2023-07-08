#ifndef KNIFE_H
#define KNIFE_H

#include<QObject>
#include<QWidget>
#include<QStatusBar>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<QApplication>
#include<QPixmap>
#include<QPainter>
#include<QTimer>
#include<QMouseEvent>
#include<QCursor>
#include<QThread>
#include<QTime>
#include<ctime>
#include<cstdlib>
#include<QTest>
#include<QThread>

class knife:public QObject,public QGraphicsItem
{
    Q_OBJECT
private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPoint point;
    QList<QPoint> p;
    int num=0;
    bool press;
    bool rep;
    bool end;
public:
    knife();
    knife(QGraphicsView *_view,QGraphicsScene *_scene);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);



};

#endif // KNIFE_H
