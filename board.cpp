#include "board.h"
#include "mainwindow.h"
#include <algorithm>

// PUBLIC METHODS
Board::Board(const unsigned int x, QGraphicsView *v)
    : columns(std::vector<std::vector<Disk*>>(nCols())),
      view(v),
      scene(new BoardScene)
{
    n = x;
    view->setScene(scene);
    view->setSceneRect(0, 0, view->frameSize().width(), view->frameSize().height());

    connect(scene, &BoardScene::BoardClick, this, &Board::BoardClick);
}

QRectF Board::boundingRect() const {
    return QRectF(0, 0, view->width(), view->height());
}

void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QBrush brush = painter->brush();
    painter->setBrush(QBrush(QColorConstants::White));
    painter->drawRect(boundingRect());
    painter->setBrush(brush);
}

unsigned int Board::getN() const {
    return n;
}

void Board::setN(const unsigned int x) {
    n = x;
}

unsigned int Board::nCols() const {
    return n + 3;
}

unsigned int Board::nRows() const {
    return n + 2;
}

bool Board::validCol(const unsigned int col) const {
    return col < nCols();
}

bool Board::validRow(const unsigned int row) const {
    return row < nRows();
}

int disk_width(int board_width, int n_cols) {
    return board_width / n_cols;
}

int Board::diskWidth() const {
    return disk_width(view->width(), nCols());
}

const Disk *Board::getDisk(unsigned int row, unsigned int col) const {
    std::vector<Disk*> column = columns[col];
    if (row < column.size()) {
        return column[row];
    } else {
        return Disk::NullDisk;
    }
}

bool Board::checkForWin(const unsigned int row, const unsigned int col, const QColor color) const {

    unsigned int count = 1, vertical = 1, horizontal = 1, diagonalLR = 1, diagonalRL = 1, i, j;

    for (i = row + 1; getDisk(i, col)->getColor() == color; i++) {
        vertical++;
    }
    for (i = row - 1; getDisk(i, col)->getColor() == color; i--) {
        vertical++;
    }
    count = std::max(count, vertical);

    for (j = col + 1; validCol(j) && getDisk(row, j)->getColor() == color; j++) {
        horizontal++;
    }
    for (j = col - 1; validCol(j) && getDisk(row, j)->getColor() == color; j--) {
        horizontal++;
    }
    count = std::max(count, horizontal);

    for (i = row + 1, j = col + 1; validRow(i) && validCol(j) && getDisk(i, j)->getColor() == color; i++, j++) {
        diagonalLR++;
    }
    for (i = row - 1, j = col - 1; validRow(i) && validCol(j) && getDisk(i, j)->getColor() == color; i--, j--) {
        diagonalLR++;
    }
    count = std::max(count, diagonalLR);

    for (i = row + 1, j = col - 1; validRow(i) && validCol(j) && getDisk(i, j)->getColor() == color; i++, j--) {
        diagonalRL++;
    }
    for (i = row - 1, j = col + 1; validRow(i) && validCol(j) && getDisk(i, j)->getColor() == color; i--, j++) {
        diagonalRL++;
    }
    count = std::max(count, diagonalRL);

    return count >= n;
}

// PROTECTED METHODS
void BoardScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);
    const QPointF pos = event->lastScenePos();

    emit BoardClick(pos);
}

// PRIVATE SLOTS
void Board::BoardClick(const QPointF pos) {
    const int x = pos.x();
    const int y = pos.y();

    const unsigned int col = x / diskWidth();
    drop_disk(col, MainWindow::getCurrentPlayer());
}

// PRIVATE METHODS
void Board::add_disk(Disk *disk) {
    scene->addItem(disk);
}

bool Board::drop_disk(const unsigned int col, const QColor color) {
    if (validCol(col)) {
        std::vector<Disk*> &column = columns[col];
        const int row = column.size();

        if (validRow(row)) {
            int x = diskWidth() * col;
            int y = diskWidth() * (nRows() - row - 1);

            Disk *disk = new Disk(x, y, color);
            add_disk(disk);
            column.push_back(disk);

            if (checkForWin(row, col, color)) {
                emit WinDetected(color);
            }

            emit Turn();
            return true;
        }
    }
    return false;
}

