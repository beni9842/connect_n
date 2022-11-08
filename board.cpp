#include "board.h"

// PUBLIC METHODS
Board::Board(const unsigned int x, QGraphicsView *v)
    : columns(std::vector<std::vector<Disk*>>(nCols())),
      view(v),
      scene(new QGraphicsScene)
{
    n = x;
    view->setScene(scene);
    view->setSceneRect(0, 0, view->frameSize().width(), view->frameSize().height());
}

unsigned int Board::getN() const {
    return n;
}

unsigned int Board::nCols() const {
    return n + 3;
}

unsigned int Board::nRows() const {
    return n + 2;
}

bool Board::validCol(const unsigned int col) const {
    return col >= 0 && col < nCols();
}

bool Board::validRow(const unsigned int row) const {
    return row >= 0 && row < nRows();
}

int Board::disk_width() const {
    int board_width = view->width();
    return board_width / nCols();
}

// PRIVATE SLOTS
void Board::DropDisk(const unsigned int col, const QColor color) {
    if (validCol(col)) {
        std::vector<Disk*> &column = get_column(col);
        const unsigned int row = column.size();
        if (validRow(row)) {
            int x = disk_width() * col;
            int y = disk_width() * (nRows() - row - 1);

            Disk *disk = new Disk(x, y, color);
            add_disk(disk);
            column.push_back(disk);
        }


    }
}

// PRIVATE METHODS
void Board::add_disk(Disk *disk) {
    scene->addItem(disk);
}

std::vector<Disk*> &Board::get_column(const unsigned int col) {
    return columns[col];
}

