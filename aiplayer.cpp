#include "aiplayer.h"

AIPlayer::AIPlayer(QObject *parent) : QObject(parent)
{
    amount = 1000;
    hand = new Hand();
}

void AIPlayer::takeCard(int card)
{
    hand->cards.push_back(card);
}

int AIPlayer::bet()
{
    amount-=20;
    emit bet_to_bank(20);
    emit ai_amount(amount);
    return 20;
}

int AIPlayer::call(int last_bet)
{
    amount -= last_bet;
    emit bet_to_bank(last_bet);
    emit ai_amount(amount);
    return last_bet;
}
