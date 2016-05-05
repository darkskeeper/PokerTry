#include "dealer.h"

Dealer::Dealer(QObject *parent) : QObject(parent)
{
    //deck.push_back(1);
    bank = 0;
    last_bet = 0;
}

void Dealer::shuffle()
{
    this->deck.clear();
    for (int i = 0; i < 52; i++)
    {
        deck.push_back(i);
    }
    int random, temp;
    for (int i = 0; i < 52; i++)
    {
        random = rand() % 52;
        temp = deck[i];
        deck[i] = deck[random];
        deck[random] = temp;
    }
}

int Dealer::giveCard()
{
    int i = rand() % deck.size();
    QVector <int> ::iterator it;
    it = deck.begin();
    it += i;
    int temp = *it;
    deck.erase(it);
    return temp;
}

int Dealer::giveBank()
{
    return bank;
}

