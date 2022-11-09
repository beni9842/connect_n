#include "board.h"

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

int disk_width(int board_width, int n_cols) {
    return board_width / n_cols;
}

int Board::diskWidth() const {
    return disk_width(view->width(), nCols());
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
    drop_disk(col, QColorConstants::Red);
}

// PRIVATE METHODS
void Board::add_disk(Disk *disk) {
    scene->addItem(disk);
}

bool Board::drop_disk(const unsigned int col, const QColor color) {
    if (validCol(col)) {
        std::vector<Disk*> &column = get_column(col);
        const unsigned int row = column.size();
        if (validRow(row)) {
            int x = diskWidth() * col;
            int y = diskWidth() * (nRows() - row - 1);

            Disk *disk = new Disk(x, y, color);
            add_disk(disk);
            column.push_back(disk);

            return true;
        }
    }
    return false;
}


std::vector<Disk*> &Board::get_column(const unsigned int col) {
    return columns[col];
}

