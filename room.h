#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include "player.h"
#include "aiplayer.h"
#include "dealer.h"
#include "table.h"

class Room : public QObject
{
    Q_OBJECT
public:
    explicit Room(QObject *parent = 0);
    Table *table;
    Player *player;
    AIPlayer *ai_player;
    Dealer *dealer;
    void startGame();

signals:
    void show(Hand *);
    void bet_to_bank(int);
    void ai_amount(int);
public slots:
};

#endif // ROOM_H
