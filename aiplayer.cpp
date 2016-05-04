#include "aiplayer.h"

AIPlayer::AIPlayer()// : QObject()
{
    amount = 1000;
}

void AIPlayer::takeCard(int card)
{
    hand.cards.push_back(card);
    /*if(hand.cards.size() == 2)
    {
        emit showai(hand);
    }*/
}

int AIPlayer::bet()
{
    amount-=20;
    return 20;
}
