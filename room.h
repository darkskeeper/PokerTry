#ifndef ROOM_H
#define ROOM_H
#include <QVector>
#include "player.h"
#include "aiplayer.h"
#include "dealer.h"
#include "table.h"

class Room
{
public:
    Table table;
    Player player;
    AIPlayer ai_player;
    Dealer dealer;
    Room();
    void startGame();
};

#endif // ROOM_H
