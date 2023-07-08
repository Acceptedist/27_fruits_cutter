
#ifndef HELP_H
#define HELP_H


#include <QWidget>
#include <QLabel>
#include <QPushButton>

class help : public QWidget
{
    Q_OBJECT
public:
    explicit help(QWidget *parent = nullptr);
private:
    QLabel* label;//内容
    QPushButton* backbutton;//返回按钮
signals:
    void back();
public slots:
    void backbuttonclick();//返回按钮被点击

};

#endif // HELP_H
