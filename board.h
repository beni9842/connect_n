#ifndef BOARD_H
#define BOARD_H

#include "disk.h"
#include <vector>
#include <QObject>
//#include <QGraphicsView>

class BoardScene: public QGraphicsScene {
    Q_OBJECT
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
signals:
    void BoardClick(const QPointF pos);
};

class Board : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Board(const unsigned int n, QGraphicsView *view);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    unsigned int getN() const;
    unsigned int nCols() const;
    unsigned int nRows() const;
    bool validCol(const unsigned int col) const;
    bool validRow(const unsigned int row) const;
    int diskWidth() const;
protected:
private slots:
    void BoardClick(const QPointF pos);
private:
    unsigned int n;
    std::vector<std::vector<Disk*>> columns;
    QGraphicsView *view;
    BoardScene *scene;

    void add_disk(Disk *disk);
    bool drop_disk(const unsigned int col, const QColor color);
    std::vector<Disk*> &get_column(const unsigned int col);
    int get_x(const unsigned int col) const;
    int get_y(const unsigned int row) const;
};

#endif // BOARD_H
