#include "disk.h"

int Disk::width = 50;

Disk::Disk(const int a, const int b, const QColor c):
    x(a),
    y(b),
    color(c)
{}

QRectF Disk::boundingRect() const {
    return QRectF(x, y, width, width);
}

QPainterPath Disk::shape() const {
    QPainterPath path;
    path.addEllipse(x, y, width, width);
    return path;
}

void Disk::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) {
    Q_UNUSED(item);
    Q_UNUSED(widget);

    QBrush brush = painter->brush();
    painter->setBrush(QBrush(color));
    painter->drawEllipse(boundingRect());
    painter->setBrush(brush);
}

int Disk::getWidth() {
    return width;
}

void Disk::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);
    qDebug() << "Click!";
}
