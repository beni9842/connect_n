#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setupdialog.h"
#include <iostream>

const std::vector<const QColor> MainWindow::players = { QColorConstants::Red, QColorConstants::Yellow };
unsigned int MainWindow::turn_count = 0;

// PUBLIC METHODS
const QColor MainWindow::getCurrentPlayer() {
    unsigned int index = turn_count % players.size();
    return players[index];
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SetupDialog *sd = new SetupDialog();
    sd->exec();

    board = new Board(sd->getN(), ui->board);
    Disk::SetWidth(board->diskWidth());

    connect(board, &Board::Turn, this, &MainWindow::Turn);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// PRIVATE SLOTS
void MainWindow::Turn() {
    turn_count++;
    std::string text = "P" + std::to_string((turn_count % players.size()) + 1);
    ui->turnIndicator->setText(QString(text.c_str()));
}
