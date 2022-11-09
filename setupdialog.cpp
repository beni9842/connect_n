#include "setupdialog.h"
#include "ui_setupdialog.h"

SetupDialog::SetupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetupDialog)
{
    ui->setupUi(this);
}

SetupDialog::~SetupDialog()
{
    delete ui;
}

unsigned int SetupDialog::getN() {
    return ui->horizontalSlider->value();
}

void SetupDialog::on_submitButton_clicked()
{
    qDebug() << getN();
    this->close();
}

