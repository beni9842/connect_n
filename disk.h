#ifndef DISK_H
#define DISK_H

#include <QObject>
#include <QGraphicsItem>
#include <QColor>
#include <QtWidgets>

class Disk : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    static int GetWidth();
    static void SetWidth(const int w);

    Disk(const int x, const int y, const QColor color);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    int getX() const;
    int getY() const;
    void setX(const int x);
    void setY(const int y);
signals:
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    int x;
    int y;
    QColor color;

    static int width;
};

#endif // DISK_H
