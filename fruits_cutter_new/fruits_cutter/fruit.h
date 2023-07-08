#ifndef FRUIT_H
#define FRUIT_H

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
#include<QSoundEffect>
#include<QTest>

#include"cutted_fruit.h"

class fruit:public QObject,public QGraphicsItem
{
    Q_OBJECT

private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPixmap fruit_pixmap;
    QTimer *timer;
    int NO;
    std::string name;
    bool fixed,rotate;
    std::string direction;
    double x,y;
    double v,v_x,v_y,a,w;
    bool not_be_cutted;//储存是否已经被切开

public:
    //构造函数。myWidget：视图类的指针。NO：水果的编号。name：水果的名字。fixed：是否在固定位置。rotate：是否持续自转。
    //        direction：clockwise为顺时针，anticlockwise是逆时针。
    //        x，y，v，a，w：初始坐标，初速度，初始与x轴正方向的夹角(0~360)，自转速度。
    fruit(QGraphicsView *_view,QGraphicsScene *_scene,int _NO=0,std::string _name="random", bool _fixed=false, bool _rotate=true,
          std::string _direction="random", double _x=-1, double _y=-1,
          double _v=-1,double _a=-1, double _w=-1);

    //析构函数。
    ~fruit();

    //图像在second秒内变透明
    void fade(double second);

signals:
    //切到水果
    void cut(std::string _name);
    //水果漏掉
    void dehealth();
    //删除水果
    void del(int _NO);

public slots:
    //每过20ms的运动
    void move_advance();

public:
    virtual QRectF boundingRect() const;
    void paint(QPainter* painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

};

#endif // FRUIT_H
