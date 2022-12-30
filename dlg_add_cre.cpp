#include "dlg_add_cre.h"
#include "ui_dlg_add_cre.h"
#include<QFile>
DlgCreAdd::DlgCreAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgCreAdd)
{
    ui->setupUi(this);
    //样式
//    this->setProperty("canMove", true);
//    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
//    QFile fread;
//    fread.setFileName(":/dlgadd.css");
//    fread.open(QIODevice::ReadOnly);
//    QString strQss=fread.readAll();
//    this->setStyleSheet(strQss);
//    fread.close();
}

DlgCreAdd::~DlgCreAdd()
{
    delete ui;
}

void DlgCreAdd::setType(bool isAdd, CreInfo info)
{
    m_isAdd=isAdd;
    cre_info=info;
//    ui->label_10->setText(QString::number(info.id));
//    ui->lineEdit->setText(info.name);
//    ui->lineEdit_2->setText(info.gender);
//    ui->lineEdit_3->setText(QString::number(info.age));
//    ui->lineEdit_4->setText(info.unit);
//    ui->lineEdit_5->setText(info.job);
//    ui->lineEdit_6->setText(info.phone);
//    ui->lineEdit_7->setText(info.address);
}

void DlgCreAdd::on_pushButton_2_clicked()
{
    this->hide();
}
/**
  确定按钮
 * @brief
 */
void DlgCreAdd::on_pushButton_clicked()
{
    CreInfo info;
    auto ptr=CreditSql::getinstance();
//    info.id=ui->label_10->text().toUInt();
//    info.name=ui->lineEdit->text();
//    info.gender=ui->lineEdit_2->text();
//    info.age=ui->lineEdit_3->text().toUInt();
//    info.unit=ui->lineEdit_4->text();
//    info.job=ui->lineEdit_5->text();
//    info.phone=ui->lineEdit_6->text();
//    info.address=ui->lineEdit_7->text();

//    if(m_isAdd)
//    {
//        ptr->addUser(info);
//    }else{
//        ptr->UpdateUserInfo(info);
//    }
//    //提示框的处理start
//        QMessageBox MBox;

//        MBox.setWindowTitle("提示");
//        MBox.setWindowIcon(QIcon(":/image/info.png"));

//        MBox.setText("操作成功！请刷新列表查看。");

//        QLabel *textlabel = MBox.findChild<QLabel*>("qt_msgbox_label"); //获取textLabel
//        if (textlabel)
//        {
//            textlabel->setAlignment(Qt::AlignCenter); //设置textLabel文本居中
//        }
//        MBox.setStyleSheet("QPushButton:hover{"
//                                "background-color: #414041;"
//                           "}"
//                           "QLabel{"
//                               "min-width: 100px;"
//                               "min-height: 60px; "
//                               "font-size: 14px;"
//                               "color: black;"
//                           "}"

//                            "QMessageBox QLabel {"
//                                "color: white;"
//                            "}"
//                          );
//        MBox.setIconPixmap(QPixmap(":/image/info.png").scaled(40, 40));
//        QPushButton *agreeBut = MBox.addButton("关闭", QMessageBox::AcceptRole);
//        MBox.exec();
//        if (MBox.clickedButton() == (QAbstractButton*)agreeBut) {
//            //在 Qt Creator 的输出窗口中输出指定字符串
//            qDebug() << "用户点击了关闭按钮";
//        }
//        //提示框的处理end

    this->hide();
}


