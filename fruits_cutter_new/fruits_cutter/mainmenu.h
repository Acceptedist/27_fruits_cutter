
#ifndef MAINMENU_H
#define MAINMENU_H

#include <QLabel>
#include <QGraphicsView>
#include <QMainWindow>
#include <QPushButton>
#include <QIcon>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <string>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QSoundEffect>
#include <QApplication>
#include "classic.h"
#include "fruit.h"
#include "knife.h"
#include "label.h"
#include "dojo.h"
#include "help.h"
#include "tips.h"
//#include "music.h"

class mainmenu:public QGraphicsView
{
    Q_OBJECT
public:
    mainmenu();
    ~mainmenu();
private:
    classic* classicgame;//游戏运行主窗口

    dojo* thedojo;//排行榜窗口
    help* thehelp;//帮助窗口
    tips* thetips;//提示窗口


    QGraphicsScene* scene;

    knife* kni;

    fruit* startclassic;//开始游戏按钮
    fruit* exit;//退出按钮
    fruit* opendojo;//排行榜按钮

    label* newgame;//开始游戏标签
    label* quit;//退出游戏标签
    label* ldojo;//排行榜标签

    bool playing=false;//正在进行游戏
    bool _startclassic=true;//开始按钮存在
    bool _exit=true;//退出按钮存在
    bool _opendojo=true;//排行榜按钮存在
    bool _help=true;//帮助按钮存在
    bool _tips=true;//提示按钮存在

    QPushButton* helpbutton;//帮助按钮
    QPushButton* tipsbutton;//提示按钮
    QPushButton* musicbutton;//音乐按钮
    bool musicstate = true;
    QMediaPlayer *m_player;
    QSoundEffect *sound;

public slots:
    void cutslot(std::string name);//某个按钮被按下
    void delclassic();//删除游戏运行窗口
    void del(int NO);//删除编号（下标）为NO的fruit
    void Dehealth();//降低生命值（中转）
    void cutcheck(std::string name);//某个fruit被切时进行检测（中转）
    void reset();//回到mainmenu（重置）
    void helpbuttonclick();//帮助按钮被按下
    void tipsbuttonclick();//提示按钮被按下
    void musicbuttonclick();//音乐按钮被按下
};

#endif // MAINMENU_H
