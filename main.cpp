#include "mainwindow.h"
#include <QApplication>
#include <time.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    srand(time(NULL));
    MainWindow w;
    //QObject::connect(&w.room.player, SIGNAL(show(Hand &)), &w, SLOT(show_players_hand(Hand &)));
    //QObject::connect(&w.room.ai_player, SIGNAL(showai(Hand &)), &w, SLOT(show_ai_players_hand(Hand &)));
    w.show();

    return app.exec();
}
