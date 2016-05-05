#ifndef AIPLAYER_H
#define AIPLAYER_H
#include "hand.h"


#include <QObject>

class AIPlayer : public QObject
{
    Q_OBJECT
public:
    explicit AIPlayer(QObject *parent = 0);
    int amount;
    Hand *hand;
    void takeCard(int);
    int bet();
    int call(int);

signals:
    void bet_to_bank(int);
    void ai_amount(int);

public slots:
};

#endif // AIPLAYER_H
