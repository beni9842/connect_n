#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    board = new Board(4, ui->board);
    Disk::SetWidth(board->disk_width());

    board->DropDisk(0, QColorConstants::Red);
    board->DropDisk(0, QColorConstants::Yellow);
    board->DropDisk(0, QColorConstants::Green);
    board->DropDisk(0, QColorConstants::Blue);
    board->DropDisk(0, QColorConstants::Magenta);
    board->DropDisk(0, QColorConstants::Red);
    board->DropDisk(0, QColorConstants::Yellow);
    board->DropDisk(0, QColorConstants::Green);
    board->DropDisk(0, QColorConstants::Blue);
    board->DropDisk(0, QColorConstants::Magenta);

}

MainWindow::~MainWindow()
{
    delete ui;
}
