#include "timer.h"

Timer::Timer(QLCDNumber *parent)
    : QTimer{parent},
      count(0)
{
    connect(this, &QTimer::timeout, this, &Timer::Tick);
}

void Timer::reset() {
    count = 0;
}

void Timer::Tick() {
    count++;
}
