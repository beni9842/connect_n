#ifndef TIMER_H
#define TIMER_H

#include <QTimer>
#include <QLCDNumber>

class Timer : public QTimer
{
    Q_OBJECT
public:
    explicit Timer(QLCDNumber *parent);
    void reset();
    unsigned int getTime() { return count; };
    ;
private slots:
    void Tick();
private:
    unsigned int count;
};

#endif // TIMER_H
