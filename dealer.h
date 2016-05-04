#ifndef DEALER_H
#define DEALER_H
#include <QVector>

class Dealer
{
public:
    int bank, last_bet;
    QVector <int> deck;
    Dealer();
    void shuffle();
    //void giveCards();
    int giveCard();
    int giveBank();
};

#endif // DEALER_H
