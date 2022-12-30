#include "data-transfer-dialog.h"
#include "ui_data-transfer-dialog.h"
#include <QDebug>
#include<QTextCodec>
#include<QFile>
#include<QLabel>
#include<QListWidget>
//#include<QChartView>
DataTransferDialog::DataTransferDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataTransferDialog)
{
    ui->setupUi(this);
    this->setProperty("canMove", true);

////    QHBoxLayout* hboxLayout = new QHBoxLayout();
//    for(int j=1;j<3;j++)
//    {
//        for (int i = 0; i < 3; i++) {
//            QListWidgetItem* item = new QListWidgetItem;
//            item->setText(QString("app%1").arg(QString::number(i)));    // item文字
//            item->setIcon(QIcon(":/image/dataTransfer.png"));      // item图片
//            item->setSizeHint(QSize(50, 70));   // item大小
//            QWidget * widget=new QWidget();

////            ui->gridLayout_2->addWidget(item, j, i);
//        }
//    }










//    ui->listWidget->setViewMode(QListWidget::IconMode);  // 设置内容为图片
//    ui->listWidget->setIconSize(QSize(50, 50));          // 设置图片的大小
//    ui->listWidget->setSpacing(10);                      // 设置每个item之间的间隔大小
//    ui->listWidget->setMovement(QListWidget::Static);    // 设置每个item不可拖动
////    ui->listWidget->setMaximumHeight(170);
//    for (int i = 0; i < 6; i++) {
//        QListWidgetItem* item = new QListWidgetItem;
//        item->setText(QString("app%1").arg(QString::number(i)));    // item文字
//        item->setIcon(QIcon(":/image/dataTransfer.png"));      // item图片
//        item->setSizeHint(QSize(50, 70));   // item大小
//        QHBoxLayout* hboxLayout = new QHBoxLayout();

//        hboxLayout->addWidget(item)
//        ui->listWidget->setLayout(hboxLayout);
//        ui->listWidget->addItem(item);       // 增加item
//    }
//    QList<QPushButton *> list_button = this->ui->groupBox->findChildren<QPushButton *>();
//    foreach (QPushButton *btn, list_button) {
//        btn->setProperty("class","trayButton");

//        QLabel* image_label_3 = new QLabel;
//        image_label_3->setFixedSize(60,60);
//        image_label_3->setStyleSheet("QLabel{border-image:url(:/image/dataTransfer.png)}");
//        QVBoxLayout *topLayout_3 = new QVBoxLayout();
//        topLayout_3->addWidget(image_label_3);
//        topLayout_3->setContentsMargins(1,1,1,1);
//        btn->setLayout(topLayout_3);
//        connect(btn, SIGNAL(clicked()), this, SLOT(setDataTrasferStyle()));
//    }


    this->setWindowFlags(Qt::WindowCloseButtonHint);
//    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    this->setProperty("canMove", true);
    this->setWindowTitle("数据交互");
    this->setWindowIcon(QIcon(":/image/transfer.png"));
    this->setFixedSize(600,400);


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
