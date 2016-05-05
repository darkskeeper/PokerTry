#ifndef PLAYER_H
#define PLAYER_H
#include "hand.h"

#include <QObject>

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = 0);
    int amount;
    Hand *hand;
    void takeCard(int);

signals:
    show(Hand*);
public slots:
};

#endif // PLAYER_H
