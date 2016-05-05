#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //table
    ui->T1_1->hide();
    ui->T1_2->hide();
    ui->T1_3->hide();
    ui->T1_4->hide();
    ui->T1_5->hide();
    is_table_ready = false;
    //player
    ui->LH1->hide();
    ui->H1_1->hide();
    ui->H1_2->hide();
    ui->betBut->hide();
    ui->BetAmountEdit->hide();
    ui->callBut->hide();
    ui->foldBut->hide();
    ui->TLcur_am->hide();
    ui->Lcur_am->hide();
    //ai_player
    ui->LH2->hide();
    ui->H2_1->hide();
    ui->H2_2->hide();
    ui->TLcur_am_ai->hide();
    ui->Lcur_am_ai->hide();
    //deal button
    ui->stgame->hide();
    //bank
    ui->TLBank->hide();
    ui->LBank->hide();

    room = new Room;

    connect(room, SIGNAL(show(Hand*)), this, SLOT(show_players_hand(Hand*)));
    connect(room, SIGNAL(bet_to_bank(int)), this, SLOT(increaseBank(int)));
    connect(room, SIGNAL(ai_amount(int)), this, SLOT(show_ai_amount(int)));
    connect(this, SIGNAL(pl_bet(int &)), SLOT(show_pl_amount(int &)));/////////////////////////////////////////////
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::parser(int card)
{
    QString str;
    if (card % 13 < 8)
    {
        str = QString::number((card % 13) + 2);
    }
    else
    {
        switch (card % 13)
        {
        case TEN:
            str = "T";
            break;
        case JACKET:
            str = "J";
            break;
        case QUEEN:
            str = "Q";
            break;
        case KING:
            str = "K";
            break;
        case ACE:
            str = "A";
            break;
        }
    }
    switch (card / 13)
    {
    case CLUBS:
        str += "♠";
        break;
    case SPADES:
        str += "♣";
        break;
    case DIAMONDS:
        str += "♦";
        break;
    case HEARTS:
        str += "♥";
        break;
    }
    return str;
}

void MainWindow::on_actionStart_Game_triggered()
{
    ui->stgame->show();
}

void MainWindow::on_actionStop_Game_triggered()
{
    //table
    ui->T1_1->hide();
    ui->T1_2->hide();
    ui->T1_3->hide();
    ui->T1_4->hide();
    ui->T1_5->hide();
    is_table_ready = false;
    //player
    ui->LH1->hide();
    ui->H1_1->hide();
    ui->H1_2->hide();
    ui->betBut->hide();
    ui->BetAmountEdit->hide();
    ui->callBut->hide();
    ui->foldBut->hide();
    ui->TLcur_am->hide();
    ui->Lcur_am->hide();
    //ai_player
    ui->LH2->hide();
    ui->H2_1->hide();
    ui->H2_2->hide();
    ui->TLcur_am_ai->hide();
    ui->Lcur_am_ai->hide();
    //deal button
    ui->stgame->hide();
    //bank
    ui->TLBank->hide();
    ui->LBank->hide();
}

void MainWindow::show_players_hand(Hand *hand)
{
    ui->LH1->show();
    ui->H1_1->show();
    ui->H1_2->show();
    ui->H1_1->setText(parser(hand->cards[0]));
    ui->H1_2->setText(parser(hand->cards[1]));
}

void MainWindow::show_ai_amount(int amount)
{
    ui->Lcur_am_ai->setText(QString::number(amount));
}

void MainWindow::on_stgame_clicked()
{
    hide_table();
    set_table_ready();
    room->startGame();
}

void MainWindow::increaseBank(int amount)
{
    room->dealer->bank += amount;
    ui->LBank->setText(QString::number(room->dealer->bank));
}

void MainWindow::on_callBut_clicked()
{
    emit pl_bet(room->dealer->last_bet);
    if (ui->T1_1->isHidden())
    {
        ui->T1_1->show();
        ui->T1_2->show();
        ui->T1_3->show();
        ui->T1_1->setText(parser(room->table->table_cards[0]));
        ui->T1_2->setText(parser(room->table->table_cards[1]));
        ui->T1_3->setText(parser(room->table->table_cards[2]));
    }
    else if(ui->T1_4->isHidden())
    {
        ui->T1_4->show();
        ui->T1_4->setText(parser(room->table->table_cards[3]));
    }
    else if(ui->T1_5->isHidden())
    {
        ui->T1_5->show();
        ui->T1_5->setText(parser(room->table->table_cards[4]));
    }
    else
    {
        ui->stgame->show();
        ui->LH2->show();
        ui->H2_1->show();
        ui->H2_2->show();
        ui->H2_1->setText(parser(room->ai_player->hand->cards[0]));
        ui->H2_2->setText(parser(room->ai_player->hand->cards[1]));
        room->player->amount+=room->dealer->giveBank();
        ui->callBut->setDisabled(true);
        ui->betBut->setDisabled(true);
        ui->foldBut->setDisabled(true);
        room->dealer->bank = 0;
    }
}

void MainWindow::on_betBut_clicked()
{
    room->player->amount-=room->dealer->last_bet;
    room->dealer->bank += room->dealer->last_bet;
    int last_bet = ui->BetAmountEdit->text().toInt();
    room->dealer->last_bet = last_bet;
    room->player->amount -= room->dealer->last_bet;
    ui->Lcur_am->setText(QString::number(room->player->amount));
    room->dealer->bank += room->dealer->last_bet;
    room->dealer->bank += room->ai_player->call(last_bet);
    ui->Lcur_am->setText(QString::number(room->ai_player->amount));
}

void MainWindow::show_pl_amount(int &cur_bet)
{
    room->player->amount-=cur_bet;
    increaseBank(cur_bet);
    ui->Lcur_am->setText(QString::number(room->player->amount));
}

void MainWindow::hide_table()
{
    ui->LH2->hide();
    ui->H2_1->hide();
    ui->H2_2->hide();
    ui->T1_1->hide();
    ui->T1_2->hide();
    ui->T1_3->hide();
    ui->T1_4->hide();
    ui->T1_5->hide();
    ui->stgame->hide();
}

void MainWindow::set_table_ready()
{
    if(!is_table_ready)
    {
        ui->TLBank->show();
        ui->LBank->show();
        ui->betBut->show();
        ui->BetAmountEdit->show();
        ui->callBut->show();
        ui->foldBut->show();
        ui->TLcur_am->show();
        ui->Lcur_am->show();
        ui->TLcur_am_ai->show();
        ui->Lcur_am_ai->show();
        is_table_ready = true;
    }
    else
    {
        ui->betBut->setDisabled(false);
        ui->callBut->setDisabled(false);
        ui->foldBut->setDisabled(false);
    }

    ui->Lcur_am->setText(QString::number(room->player->amount));

    ui->Lcur_am_ai->setText(QString::number(room->ai_player->amount));
    room->dealer->last_bet = room->ai_player->bet();
    ui->LBank->setText(QString::number(room->dealer->bank));
}
