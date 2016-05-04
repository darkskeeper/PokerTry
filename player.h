#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"
#include <QObject>

class Player// : public QObject
{
    //Q_OBJECT
public:
    int amount;
    Hand hand;
    Player();
    void takeCard(int);
/*signals:
    show(const Hand&);*/
};

#endif // PLAYER_H
