#include "disk.h"

int Disk::width = 0;

int Disk::GetWidth() {
    return width;
}

void Disk::SetWidth(const int w) {
    width = w;
}

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

void Disk::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);
    qDebug() << "Click!";
}
