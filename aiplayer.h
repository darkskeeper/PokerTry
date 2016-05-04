#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "hand.h"
#include <QObject>

class AIPlayer// : public QObject
{
    //Q_OBJECT
public:
    int amount;
    Hand hand;
    AIPlayer();
    void takeCard(int);
    int bet();
/*signals:
    showai(const Hand&);*/
};

#endif // AIPLAYER_H
