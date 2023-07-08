
#ifndef DOJO_H
#define DOJO_H

#include <fstream>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFile>

class dojo : public QWidget
{
    Q_OBJECT
public:
    explicit dojo(QWidget *parent = nullptr);
private:
    QLabel* label;//内容
    QPushButton* backbutton;//返回按钮
signals:
    void back();
public slots:
    void backbuttonclick();//返回按钮被点击
};

#endif // DOJO_H
