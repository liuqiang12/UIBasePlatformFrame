#include "data-transfer-dialog.h"
#include "ui_data-transfer-dialog.h"

DataTransferDialog::DataTransferDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataTransferDialog)
{
    ui->setupUi(this);


    this->setWindowFlags(Qt::WindowCloseButtonHint);
//    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    this->setProperty("canMove", true);
    this->setWindowTitle("数据交互");
    this->setWindowIcon(QIcon(":/image/transfer.png"));


}

DataTransferDialog::~DataTransferDialog()
{
    delete ui;
}
