#include "data-transfer-dialog.h"
#include "ui_data-transfer-dialog.h"
#include <QDebug>
#include<QTextCodec>
#include<QFile>
#include<QLabel>
#include<QListWidget>
#include<QGraphicsDropShadowEffect>
#include<QPalette>

DataTransferDialog::DataTransferDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataTransferDialog)
{
    ui->setupUi(this);
    this->setBackgroundRole(QPalette::NoRole);
    //渐变色start
    QGraphicsDropShadowEffect *shadow=new QGraphicsDropShadowEffect(this);
    shadow->setOffset(0);
    shadow->setBlurRadius(20);
    shadow->setColor(Qt::darkGreen);



    this->setGraphicsEffect(shadow);
    //渐变色start
    this->setStyleSheet("QDialog{background-color:#c1d1e9}");
    this->setMouseTracking(true);//追踪鼠标


    this->setProperty("canMove", true);
    QList<QPushButton *> list_pushButton = this->ui->groupBox->findChildren<QPushButton *>();
    foreach (QPushButton *lb, list_pushButton) {
        lb->setProperty("class","trayButton");
        lb->setFlat(true);
        QString curItem_text=lb->text();

        if(curItem_text.contains("计划任务接收",Qt::CaseInsensitive))
        {
           //不区分大小写
           lb->setProperty("flag","jhrwjs");
        }
        if(curItem_text.contains("清点物资同步",Qt::CaseInsensitive))
        {
           //不区分大小写
           lb->setProperty("flag","wzqdtb");
        }
        if(curItem_text.contains("异常数据检验",Qt::CaseInsensitive))
        {
           //不区分大小写
           lb->setProperty("flag","ycsjjy");
        }
        if(curItem_text.contains("基础资源同步",Qt::CaseInsensitive))
        {
           //不区分大小写
           lb->setProperty("flag","jczytb");
        }

        if(curItem_text.contains("数据引接",Qt::CaseInsensitive))
        {
           //不区分大小写
           lb->setProperty("flag","sjyj");
        }

        if(curItem_text.contains("通知公告",Qt::CaseInsensitive))
        {
           //不区分大小写
           lb->setProperty("flag","tzgg");
        }
    }

    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setProperty("canMove", true);
    this->setWindowTitle("数据交互");
    this->setWindowIcon(QIcon(":/image/transfer.png"));
    this->setFixedSize(550,350);


    QFile fread;
    fread.setFileName(":/trayButton.css");
    fread.open(QIODevice::ReadOnly);
    QString strQss=fread.readAll();
    this->setStyleSheet(strQss);
    fread.close();
}

DataTransferDialog::~DataTransferDialog()
{
    delete ui;
}
//数据传输的样式设定
void DataTransferDialog::setDataTrasferStyle(){
//    QPushButton *pushBtn = (QPushButton *)sender();
//    QString text = pushBtn->text();

//    QList<QPushButton *> tbtns = ui->groupBox->findChildren<QPushButton *>();
//    foreach (QPushButton *btn, tbtns) {
//        if (btn == pushBtn) {
//            btn->setChecked(true);
//        } else {
//            btn->setChecked(false);
//        }
//    }

//    qDebug() << text.toStdString().c_str();   //正确输出中文

}
