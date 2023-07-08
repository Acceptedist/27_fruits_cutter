
#ifndef SCORE_H
#define SCORE_H

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
#include<QTest>
#include<QSoundEffect>


class score:public QObject,public QGraphicsItem
{
    Q_OBJECT
private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    QTimer *timer;
    int sc;
    double x,y;
    bool start=false;//游戏是否开始
public:
    score();
    score(QGraphicsView *_view,QGraphicsScene *_scene);
    score(QGraphicsView *_view,QGraphicsScene *_scene,double x1,double y1);
    int getscore();
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
signals:
    int updatescore(int sc);
public slots:
    void checkscore(std::string name);
};

#endif // SCORE_H
