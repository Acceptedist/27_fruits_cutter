
#include "score.h"

score::score():sc(0),x(60),y(60)
{

}

score::score(QGraphicsView *_view, QGraphicsScene *_scene):sc(0),x(60),y(60)
{
    view=_view;
    scene=_scene;

}

score::score(QGraphicsView *_view, QGraphicsScene *_scene, double x1, double y1):sc(0),x(x1),y(y1)
{
    view=_view;
    scene=_scene;
}

QRectF score::boundingRect() const
{
    return QRectF(40,0,760,60);
}

void score::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option,
                  QWidget *widget)
{
    QPen mypen;
    mypen.setColor(Qt::white);//字体颜色，觉得丑可以改
    painter->setPen(mypen);
    QFont font1("KaiTi",20);//字体以及大小，同上
    painter->setFont(font1);
    painter->drawText(x,y,"得分：");
    painter->drawText(x+80,y,QString::number(sc));
    //hp--;监测点
    update();
}


void score::checkscore(std::string name)
{
    if(name[1]!='o')
    {

        QSoundEffect *fruitsound=new QSoundEffect(this);
        fruitsound->setSource(QUrl("qrc:/fruit_sound.wav"));
        fruitsound->setVolume(0.5f);
        fruitsound->play();

        sc+=10;
    }
    // emit updatescore(sc);
}

int score::getscore()
{
    return sc;
}
