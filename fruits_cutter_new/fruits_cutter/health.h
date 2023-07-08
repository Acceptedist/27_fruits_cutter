#ifndef HEALTH_H
#define HEALTH_H


#include<QObject>
#include<QWidget>
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

class health:public QObject,public QGraphicsItem
{
    Q_OBJECT
private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    int hp;
    double x,y;
    QTimer *timer;
    bool start=false;
public:
    health();
    health(QGraphicsView *_view,QGraphicsScene *_scene);
    health(QGraphicsView *_view,QGraphicsScene *_scene,double x1,double y1);


    int gethealth();

    virtual QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
signals:
    void zero();
public slots:
    void dehealth();
    void checkhealth(std::string name);
};

#endif // HEALTH_H
