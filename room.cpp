#include "room.h"

Room::Room()
{

}

void Room::startGame()
{
    dealer.shuffle();
    player.hand.cards.clear();
    ai_player.hand.cards.clear();
    for(int i = 0; i < 5; i++)
    {
        if (i<2)
        {
            player.takeCard(dealer.giveCard());
            ai_player.takeCard(dealer.giveCard());
        }
        table.table_cards.push_back(dealer.giveCard());
    }
}
