#ifndef SETUPDIALOG_H
#define SETUPDIALOG_H

#include <QDialog>

namespace Ui {
class SetupDialog;
}

class SetupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetupDialog(QWidget *parent = nullptr);
    ~SetupDialog();
    unsigned int getN();
private slots:
    void on_submitButton_clicked();

private:
    Ui::SetupDialog *ui;
};

#endif // SETUPDIALOG_H
