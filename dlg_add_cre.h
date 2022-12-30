#ifndef DLG_ADD_CRE_H
#define DLG_ADD_CRE_H
#include"creditsql.h"
#include <QDialog>

namespace Ui {
class DlgCreAdd;
}

class DlgCreAdd : public QDialog
{
    Q_OBJECT

public:
    explicit DlgCreAdd(QWidget *parent = nullptr);
       ~DlgCreAdd();
       void setType(bool isAdd, CreInfo info={});
private slots:
//    void btn_uconfim_clicked();

   void on_pushButton_2_clicked();

   void on_pushButton_clicked();
private:
    Ui::DlgCreAdd *ui;
    bool m_isAdd;
    int m_id;
    CreInfo cre_info;
};

#endif // DLG_ADD_CRE_H
