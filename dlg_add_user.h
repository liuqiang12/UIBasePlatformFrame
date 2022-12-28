#ifndef DLG_ADD_USER_H
#define DLG_ADD_USER_H
#include"sonsql.h"
#include <QDialog>

namespace Ui {
class dlg_add_user;
}

class dlg_add_user : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_add_user(QWidget *parent = nullptr);
    ~dlg_add_user();
    void setType(bool isAdd, UserInfo info={});
private slots:
//    void btn_uconfim_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::dlg_add_user *ui;
    bool m_isAdd;
    int m_id;
    UserInfo m_info;
};

#endif // DLG_ADD_USER_H
