#ifndef DLG_ADD_H
#define DLG_ADD_H

#include <QDialog>
#include"rtsql.h"
#include<QFile>
namespace Ui {
class dlg_add;
}

class dlg_add : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_add(QWidget *parent = nullptr);
    ~dlg_add();
    void setType(bool isAdd,PerInfo info={});
private slots:
    void on_btn_add_clicked();

    void on_btn_canncel_clicked();

private:
    Ui::dlg_add *ui;
    bool m_isAdd;
    int m_id;
    PerInfo m_info;
};

#endif // DLG_ADD_H
//25
