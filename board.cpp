#include "board.h"

Board::Board(const unsigned int x, QGraphicsView *v)
    : n(x),
      columns(std::vector<std::vector<Disk*>>(nCols())),
      view(v),
      scene(new QGraphicsScene)
{
    view->setScene(scene);
    view->setSceneRect(0, 0, view->frameSize().width(), view->frameSize().height());

    add_disk(new Disk(100, 100, QColorConstants::Red));
}

unsigned int Board::getN() {
    return n;
}

unsigned int Board::nCols() {
    return n + 3;
}

unsigned int Board::nRows() {
    return n + 2;
}

void Board::add_disk(Disk *disk) {
    scene->addItem(disk);
}
