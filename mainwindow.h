#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "board.h"

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
private slots:
    void Turn();
private:
    static unsigned int turn_count;
    static const std::vector<const QColor> players;

    Ui::MainWindow *ui;
    Board *board;
};

#endif // MAINWINDOW_H
