#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T17:39:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Poker_v_1_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    aiplayer.cpp \
    dealer.cpp \
    hand.cpp \
    player.cpp \
    room.cpp \
    table.cpp

HEADERS  += mainwindow.h \
    aiplayer.h \
    dealer.h \
    hand.h \
    player.h \
    room.h \
    table.h

FORMS    += mainwindow.ui

DISTFILES +=
