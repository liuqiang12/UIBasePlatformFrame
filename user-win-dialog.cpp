#include "user-win-dialog.h"
#include "ui_user-win-dialog.h"
#include<QMessageBox>
#include<QDebug>
#include<QFile>
#include <QDesktopWidget>
#include <QWidget>
#include<QLabel>




UserWinDialog::UserWinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserWinDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    this->setProperty("canMove", true);
    this->setWindowTitle("人员准入");
    this->setWindowIcon(QIcon(":/image/window-default-tip.png"));


    QFile fread;
    fread.setFileName(":/winDialog.css");
    fread.open(QIODevice::ReadOnly);
    QString strQss=fread.readAll();
    this->setStyleSheet(strQss);
    fread.close();
}

UserWinDialog::~UserWinDialog()
{
    delete ui;
}

//void UserWinDialog::on_buttonBox_clicked(QAbstractButton *button)
//{
//    //提示框的处理start

//}
//弹出框保存按钮
void UserWinDialog::on_pushButton_clicked()
{
    QMessageBox MBox;

    MBox.setWindowTitle("提示");
    MBox.setWindowIcon(QIcon(":/image/info.png"));
    MBox.setText("操作成功！请刷新列表查看。");
    MBox.setIconPixmap(QPixmap(":/image/info.png").scaled(40, 40));
    QPushButton *agreeBut = MBox.addButton("关闭", QMessageBox::AcceptRole);
    MBox.exec();
    if (MBox.clickedButton() == (QAbstractButton*)agreeBut) {
        //打印日志
        qDebug() << QString::fromLocal8Bit("click close button");
    }
    //提示框的处理end
}

void UserWinDialog::on_pushButton_2_clicked()
{
    this->hide();
}
