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
    unsigned int getN() const;
    unsigned int nCols() const;
    unsigned int nRows() const;
    bool validCol(const unsigned int col) const;
    bool validRow(const unsigned int row) const;
    int disk_width() const;

    void DropDisk(const unsigned int column, const QColor color);
private slots:

private:
    unsigned int n;
    std::vector<std::vector<Disk*>> columns;
    QGraphicsView *view;
    QGraphicsScene *scene;

    void add_disk(Disk *disk);
    std::vector<Disk*> &get_column(const unsigned int col);
    int get_x(const unsigned int col) const;
    int get_y(const unsigned int row) const;
};

#endif // BOARD_H
