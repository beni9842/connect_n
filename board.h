#ifndef BOARD_H
#define BOARD_H

#include "disk.h"
#include <vector>
#include <QObject>
//#include <QGraphicsView>

class Board : public QObject
{
    Q_OBJECT
public:
    explicit Board(const unsigned int n, QGraphicsView *view);
    unsigned int getN();
    unsigned int nCols();
    unsigned int nRows();
private slots:
private:
    unsigned int n;
    std::vector<std::vector<Disk*>> columns;
    QGraphicsView *view;
    QGraphicsScene *scene;

    void add_disk(Disk *disk);
};

#endif // BOARD_H
