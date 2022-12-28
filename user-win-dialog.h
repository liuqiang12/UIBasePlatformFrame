#ifndef USERWINDIALOG_H
#define USERWINDIALOG_H

#include <QDialog>
#include<QAbstractButton>
#include<QMessageBox>
#include<QDebug>
#include<QFile>
#include<QDesktopWidget>
#include<QWidget>
namespace Ui {
class UserWinDialog;
}

class UserWinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserWinDialog(QWidget *parent = nullptr);
    ~UserWinDialog();

private slots:
//    void on_buttonBox_clicked(QAbstractButton *button);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::UserWinDialog *ui;
};

#endif // USERWINDIALOG_H
