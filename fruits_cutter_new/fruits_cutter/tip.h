
#ifndef TIP_H
#define TIP_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>


class tip
{
private:
    QLabel* label;//内容
    QPushButton* backbutton;//返回按钮
signals:
    void back();
public slots:
    void backbuttonclick();//返回按钮被点击
};

#endif // TIP_H
