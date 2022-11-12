#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "board.h"
// #include "timer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static const QColor getCurrentPlayer();
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
private slots:
    void Turn();
    void WinDetected(const QColor winner);
    void InitBoard(const unsigned int n);
private:
    static unsigned int turn_count;
    static const std::vector<const QColor> players;

    Ui::MainWindow *ui;
    Board *board;
    // Timer *timer;
};

#endif // MAINWINDOW_H
