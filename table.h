#ifndef TABLE_H
#define TABLE_H

#include <QObject>
#include <QVector>

class Table : public QObject
{
    Q_OBJECT
public:
    explicit Table(QObject *parent = 0);
    QVector <int> table_cards;

signals:

public slots:
};

#endif // TABLE_H
