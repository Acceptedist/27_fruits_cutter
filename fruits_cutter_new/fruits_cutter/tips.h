
#ifndef TIPS_H
#define TIPS_H


#include <QWidget>
#include <QLabel>
#include <QPushButton>

class tips : public QWidget
{
    Q_OBJECT
public:
    explicit tips(QWidget *parent = nullptr);
private:
    QLabel* label;//内容
    QPushButton* backbutton;//返回按钮
signals:
    void back();
public slots:
    void backbuttonclick();//返回按钮被点击

};

#endif // TIPS_H
