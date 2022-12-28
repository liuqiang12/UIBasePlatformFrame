#ifndef DATATRANSFERDIALOG_H
#define DATATRANSFERDIALOG_H

#include <QDialog>

namespace Ui {
class DataTransferDialog;
}

class DataTransferDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DataTransferDialog(QWidget *parent = nullptr);
    ~DataTransferDialog();

private:
    Ui::DataTransferDialog *ui;
//插槽
private slots:
    //数据传输样式
    void setDataTrasferStyle();
};


#endif // DATATRANSFERDIALOG_H
