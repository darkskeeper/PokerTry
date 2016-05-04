#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T13:05:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Poker_v_1_0
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    room.cpp \
    player.cpp \
    aiplayer.cpp \
    hand.cpp \
    dealer.cpp \
    table.cpp

HEADERS  += mainwindow.h \
    room.h \
    player.h \
    aiplayer.h \
    hand.h \
    dealer.h \
    table.h

FORMS    += mainwindow.ui
