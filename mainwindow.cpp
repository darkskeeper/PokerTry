#include "mainwindow.h"
#include "ui_mainwindow.h"

const int SUITS = 4;
const int ONE_SUIT = 13;
const int N_CARDS_HAND = 2;
const int N_CARDS = 52;
const int N_CARDS_TABLE = 5;

enum RANK { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACKET, QUEEN, KING, ACE };
enum COMBINATIONS { HIGH_CARD, PAIR, TWO_PAIRS, THREE_OF_A_KIND, STRAIGHT, FLASH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLASH, ROYAL_FLASH };
enum SUIT { CLUBS, SPADES, DIAMONDS, HEARTS };
const QString c[10] = { "HIGH_CARD", "PAIR", "TWO_PAIRS", "THREE_OF_A_KIND", "STRAIGHT", "FLASH", "FULL_HOUSE", "FOUR_OF_A_KIND", "STRAIGHT_FLASH", "ROYAL_FLASH" };

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->T1_1->hide();
    ui->T1_2->hide();
    ui->T1_3->hide();
    ui->T1_4->hide();
    ui->T1_5->hide();
    ui->LH1->hide();
    ui->H1_1->hide();
    ui->H1_2->hide();
    ui->LH2->hide();
    ui->H2_1->hide();
    ui->H2_2->hide();
    ui->betBut->hide();
    ui->BetAmountEdit->hide();
    ui->callBut->hide();
    ui->foldBut->hide();
    ui->TLcur_am->hide();
    ui->Lcur_am->hide();
    ui->stgame->hide();
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
    /*ui->LH1->show();
    ui->H1_1->show();
    ui->H1_2->show();
    ui->LH2->show();
    ui->H2_1->show();
    ui->H2_2->show();
    //ui->betBut->show();
    //ui->BetAmountEdit->show();
    //ui->callBut->show();
    //ui->foldBut->show();
    //ui->TLcur_am->show();
    //ui->Lcur_am->show();
    room.startGame();
    ui->H1_1->setText(parser(room.player.hand.cards[0]));
    ui->H1_2->setText(parser(room.player.hand.cards[1]));
    ui->H2_1->setText(parser(room.ai_player.hand.cards[0]));
    ui->H2_2->setText(parser(room.ai_player.hand.cards[1]));*/
}


void MainWindow::on_actionStop_Game_triggered()
{
    ui->stgame->hide();
    /*ui->LH1->hide();
    ui->H1_1->hide();
    ui->H1_2->hide();

    ui->LH2->hide();
    ui->H2_1->hide();
    ui->H2_2->hide();

    ui->betBut->hide();
    ui->BetAmountEdit->hide();
    ui->callBut->hide();
    ui->foldBut->hide();
    ui->TLcur_am->hide();
    ui->Lcur_am->hide();*/
}

/*void MainWindow::show_players_hand(Hand &hand)
{
    ui->H1_1->setText(parser(hand.cards[0]));
    ui->H1_2->setText(parser(hand.cards[1]));
}

void MainWindow::show_ai_players_hand(Hand &hand)
{
    ui->H2_1->setText(parser(hand.cards[0]));
    ui->H2_2->setText(parser(hand.cards[1]));
}*/

void MainWindow::on_stgame_clicked()
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
    room.startGame();
    ui->LH1->show();
    ui->H1_1->show();
    ui->H1_2->show();
    ui->H1_1->setText(parser(room.player.hand.cards[0]));
    ui->H1_2->setText(parser(room.player.hand.cards[1]));
    ui->betBut->show();
    ui->BetAmountEdit->show();
    ui->callBut->show();
    ui->foldBut->show();
    ui->callBut->setDisabled(false);
    ui->betBut->setDisabled(false);
    ui->foldBut->setDisabled(false);
    ui->TLcur_am->show();
    ui->Lcur_am->show();
    ui->Lcur_am->setText(QString::number(room.player.amount));
    room.dealer.bank = 0;
    room.dealer.last_bet = room.ai_player.bet();
    room.dealer.bank += room.dealer.last_bet;
}

void MainWindow::on_callBut_clicked()
{
    room.player.amount-=room.dealer.last_bet;
    room.dealer.bank += room.dealer.last_bet;
    ui->Lcur_am->setText(QString::number(room.player.amount));
    if (ui->T1_1->isHidden())
    {
        ui->T1_1->show();
        ui->T1_2->show();
        ui->T1_3->show();
        ui->T1_1->setText(parser(room.table.table_cards[0]));
        ui->T1_2->setText(parser(room.table.table_cards[1]));
        ui->T1_3->setText(parser(room.table.table_cards[2]));
    }
    else if(ui->T1_4->isHidden())
    {
        ui->T1_4->show();
        ui->T1_4->setText(parser(room.table.table_cards[3]));
    }
    else if(ui->T1_5->isHidden())
    {
        ui->T1_5->show();
        ui->T1_5->setText(parser(room.table.table_cards[4]));
    }
    else
    {
        ui->stgame->show();
        ui->LH2->show();
        ui->H2_1->show();
        ui->H2_2->show();
        ui->H2_1->setText(parser(room.ai_player.hand.cards[0]));
        ui->H2_2->setText(parser(room.ai_player.hand.cards[1]));
        room.player.amount+=room.dealer.giveBank();
        ui->callBut->setDisabled(true);
        ui->betBut->setDisabled(true);
        ui->foldBut->setDisabled(true);
    }
}
