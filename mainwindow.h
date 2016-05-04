#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "room.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Room room;
    QString parser(int);

private slots:
    void on_actionStart_Game_triggered();

    void on_actionStop_Game_triggered();

    void on_stgame_clicked();

/*public slots:
    void show_players_hand(Hand &);
    void show_ai_players_hand(Hand &);*/

    void on_callBut_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
