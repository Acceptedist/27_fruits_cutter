
#ifndef CLASSIC_H
#define CLASSIC_H


#include <QGraphicsView>
#include <QMainWindow>
#include <QPushButton>
#include <QIcon>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <ctime>
#include <QLabel>
#include <fstream>
#include <algorithm>
#include "fruit.h"
#include "knife.h"
#include "health.h"
#include "score.h"

class classic: public QGraphicsView
{
    Q_OBJECT

public:
    classic();
    virtual ~classic();
private:
    QGraphicsScene* scene;
    QTimer *point_timer;
    QList<QGraphicsLineItem*> linelist;

    QTimer* born_timer;//产生水果的计时器
    int num=0;//index pointer
    fruit* all_fruits[10050];//存储所有的水果
    QTimer* bomb_born_timer;//产生炸弹的计时器

    knife* kni;//刀

    health* hea;//生命值

    score* sco;//计分器

    bool eog=false;//end of game

    QPoint point;
    QList<QPoint> p;
    int num1=0;
    int num2=0;
    bool press;
    bool rep;
public:
    void update_dojo();//更新排行榜
signals:
    void dehealth();//降低生命值
    void check(std::string name);//某个fruit被切时进行检测
    void end();
public slots:
    void born();//产生水果
    void bomb_born();//产生炸弹
    void del(int NO);//删除编号（下标）为NO的fruit
    void Dehealth();//降低生命值（中转）
    void cutcheck(std::string name);//某个fruit被切时进行检测（中转）
    void endgame(); //游戏结束
    void getpoint();

};

/*
 * 需要添加的内容：
 * 1.加载所有图片
 * 2.在fruit类构造函数中添加：connect(this,SIGNAL(del()),*parent*,SLOT(*parent*->del()));
 * 3.在fruit类构造函数中添加：connect(this,SIGNAL(dehealth()),*parent*,SLOT(*parent*->Dehealth()));
 * 4.在fruit类构造函数中添加；connect(this,SIGNAL(cut(std::string name)),*parent*,SLOT(*parent*->cutcheck(std::string name)));
*/

#endif // CLASSIC_H
