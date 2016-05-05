#ifndef DEALER_H
#define DEALER_H

#include <QObject>
#include <QVector>

class Dealer : public QObject
{
    Q_OBJECT
public:
    explicit Dealer(QObject *parent = 0);
    int bank, last_bet;
    QVector <int> deck;
    void shuffle();
    int giveCard();
    int giveBank();

signals:

public slots:
};

#endif // DEALER_H
