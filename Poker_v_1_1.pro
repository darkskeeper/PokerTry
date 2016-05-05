#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T12:05:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Poker_v_1_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    room.cpp \
    aiplayer.cpp \
    dealer.cpp \
    hand.cpp \
    table.cpp \
    player.cpp

HEADERS  += mainwindow.h \
    room.h \
    aiplayer.h \
    dealer.h \
    hand.h \
    table.h \
    player.h

FORMS    += mainwindow.ui
