#include "room.h"

Room::Room(QObject *parent) : QObject(parent)
{
    dealer = new Dealer();
    player = new Player();
    ai_player = new AIPlayer();
    table = new Table();
    connect(this->player, SIGNAL(show(Hand*)), SIGNAL(show(Hand*)));
    connect(this->ai_player, SIGNAL(bet_to_bank(int)), SIGNAL(bet_to_bank(int)));
    connect(this->ai_player, SIGNAL(ai_amount(int)), SIGNAL(ai_amount(int)));
}

void Room::startGame()
{
    dealer->shuffle();
    player->hand->cards.clear();
    ai_player->hand->cards.clear();
    for(int i = 0; i < 5; i++)
    {
        if (i<2)
        {
            player->takeCard(dealer->giveCard());
            ai_player->takeCard(dealer->giveCard());
        }
        table->table_cards.push_back(dealer->giveCard());
    }
}
