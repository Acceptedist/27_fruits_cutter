
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "classic.h"
#include <QMainWindow>
#include <QPushButton>
#include <QIcon>
#include <QMediaPlayer>
#include <QSoundEffect>//音频类
#include <QAudioOutput>

#include "mainmenu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QPushButton* startbutton;//开始按钮
    mainmenu* menu;//主菜单
    classic* test;//测试用

//槽函数
public slots:
    void startbuttonclick();//开始按钮被点击
};

#endif // MAINWINDOW_H
