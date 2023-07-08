QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


QT +=testlib
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QT += multimedia
QT += multimediawidgets

SOURCES += \
    classic.cpp \
    cutted_fruit.cpp \
    dojo.cpp \
    fruit.cpp \
    health.cpp \
    help.cpp \
    knife.cpp \
    label.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    score.cpp \
    tips.cpp

HEADERS += \
    classic.h \
    cutted_fruit.h \
    dojo.h \
    fruit.h \
    health.h \
    help.h \
    knife.h \
    label.h \
    mainmenu.h \
    mainwindow.h \
    score.h \
    tips.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    fruits_cutter_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# 设置应用图标
RC_ICONS=favicon.ico

RESOURCES += \
    img.qrc \
    music.qrc

DISTFILES += \
    bgm.wav
