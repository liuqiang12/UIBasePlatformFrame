#include "data-transfer-dialog.h"
#include "ui_data-transfer-dialog.h"

DataTransferDialog::DataTransferDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataTransferDialog)
{
    ui->setupUi(this);
}

DataTransferDialog::~DataTransferDialog()
{
    delete ui;
}
