/********************************************************************************
** Form generated from reading UI file 'score.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCORE_H
#define UI_SCORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_score
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *score)
    {
        if (score->objectName().isEmpty())
            score->setObjectName("score");
        score->resize(800, 600);
        centralwidget = new QWidget(score);
        centralwidget->setObjectName("centralwidget");
        score->setCentralWidget(centralwidget);
        menubar = new QMenuBar(score);
        menubar->setObjectName("menubar");
        score->setMenuBar(menubar);
        statusbar = new QStatusBar(score);
        statusbar->setObjectName("statusbar");
        score->setStatusBar(statusbar);

        retranslateUi(score);

        QMetaObject::connectSlotsByName(score);
    } // setupUi

    void retranslateUi(QMainWindow *score)
    {
        score->setWindowTitle(QCoreApplication::translate("score", "score", nullptr));
    } // retranslateUi

};

namespace Ui {
    class score: public Ui_score {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCORE_H
