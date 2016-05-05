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
    Room *room;
    QString parser(int);

private slots:
    void on_actionStart_Game_triggered();
    void on_actionStop_Game_triggered();
    void on_stgame_clicked();

public slots:
    void increaseBank(int);
    void show_players_hand(Hand *);
    void show_ai_amount(int);
    void on_callBut_clicked();
    void on_betBut_clicked();
    void show_pl_amount(int &);
signals:
    void pl_bet(int &);
private:
    Ui::MainWindow *ui;
    void hide_table();
    bool is_table_ready;
    void set_table_ready();
};

#endif // MAINWINDOW_H
