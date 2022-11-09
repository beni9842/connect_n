#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    board = new Board(4, ui->board);

    Disk::SetWidth(board->diskWidth());
}

MainWindow::~MainWindow()
{
    delete ui;
}

