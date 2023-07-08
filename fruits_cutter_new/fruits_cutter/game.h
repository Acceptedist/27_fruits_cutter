
#ifndef GAME_H
#define GAME_H

#include <QWindow>
#include <QPushButton>
#include <QIcon>

class game:public QWindow,public QWidget
{
    Q_OBJECT
public:
    game();
};

#endif // GAME_H
