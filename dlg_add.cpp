#include "dlg_add.h"
#include "ui_dlg_add.h"

dlg_add::dlg_add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_add)
{
    ui->setupUi(this);
    ui->sBox_age->setRange(0, 150);
    ui->sBox_age->setValue(18);
    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    QFile fread;
    fread.setFileName(":/dlgadd.css");
    fread.open(QIODevice::ReadOnly);
    QString strQss=fread.readAll();
    this->setStyleSheet(strQss);
    fread.close();
}

dlg_add::~dlg_add()
{
    delete ui;
}

void dlg_add::setType(bool isAdd, PerInfo info)
{
    m_isAdd=isAdd;
    m_info=info;
    ui->label_2->setText(QString::number(info.id));
    ui->le_name->setText(info.name);
    ui->le_gender->setText(info.gender);
    ui->sBox_age->setValue(info.age);
    ui->le_school->setText(info.school);
    ui->le_time->setText(info.time);
    ui->le_phone->setText(info.phone);
    ui->le_mail->setText(info.email);
}

void dlg_add::on_btn_add_clicked()
{
    PerInfo info;
    auto ptr=rtSql::getinstance();
    info.id=ui->label_2->text().toUInt();
    info.name=ui->le_name->text();
    info.gender=ui->le_gender->text();
    info.age=ui->sBox_age->text().toUInt();
    info.school=ui->le_school->text();
    info.time=ui->le_time->text();
    info.phone=ui->le_phone->text();
    info.email=ui->le_mail->text();

    if(m_isAdd)
    {
        ptr->addPer(info);
    }else{
        ptr->UpdatePerInfo(info);
    }
    QMessageBox::information(nullptr,"信息","存储成功");
    this->hide();
}

void dlg_add::on_btn_canncel_clicked()
{
    this->hide();
}
