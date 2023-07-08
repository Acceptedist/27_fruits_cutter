
#include "game.h"

game::game()
{
    //设置窗口标题、大小
    this->resize(960,720);
    this->setWindowTitle("fruits_cutter");
    //this->setWindowIcon(...);

    //设置背景
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/img/backboard.png")));
    this->setPalette(palette);
}

