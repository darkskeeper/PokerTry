#include "player.h"

Player::Player()// : QObject()
{
    amount = 1000;
}


void Player::takeCard(int card)
{
    hand.cards.push_back(card);
    /*if(hand.cards.size() == 2)
    {
        emit show(hand);
    }*/
}
