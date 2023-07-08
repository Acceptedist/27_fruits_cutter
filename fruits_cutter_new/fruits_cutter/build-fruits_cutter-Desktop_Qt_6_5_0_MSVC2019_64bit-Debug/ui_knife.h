/********************************************************************************
** Form generated from reading UI file 'knife.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KNIFE_H
#define UI_KNIFE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_knife
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *knife)
    {
        if (knife->objectName().isEmpty())
            knife->setObjectName("knife");
        knife->resize(800, 600);
        centralwidget = new QWidget(knife);
        centralwidget->setObjectName("centralwidget");
        knife->setCentralWidget(centralwidget);
        menubar = new QMenuBar(knife);
        menubar->setObjectName("menubar");
        knife->setMenuBar(menubar);
        statusbar = new QStatusBar(knife);
        statusbar->setObjectName("statusbar");
        knife->setStatusBar(statusbar);

        retranslateUi(knife);

        QMetaObject::connectSlotsByName(knife);
    } // setupUi

    void retranslateUi(QMainWindow *knife)
    {
        knife->setWindowTitle(QCoreApplication::translate("knife", "knife", nullptr));
    } // retranslateUi

};

namespace Ui {
    class knife: public Ui_knife {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KNIFE_H
