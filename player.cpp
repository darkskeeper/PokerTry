#include "player.h"

Player::Player(QObject *parent) : QObject(parent)
{
    amount = 1000;
    hand = new Hand();
}


void Player::takeCard(int card)
{
    hand->cards.push_back(card);
    if(hand->cards.size() == 2)
    {
        emit show(hand);
    }
}

