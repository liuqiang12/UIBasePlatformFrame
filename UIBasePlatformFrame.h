#ifndef UIDEMO08_H
#define UIDEMO08_H
#include<QTreeWidgetItem>
#include <QWidget>
#include"rtsql.h"
#include"dlg_add.h"
#include"sonsql.h"
#include<QRandomGenerator>
#include"dlg_add_user.h"
#include<QHostInfo>
#include<QHostAddress>
#include<QNetworkInterface>
#include<QValueAxis>
#include<QSplineSeries>
#include<QAreaSeries>
#include<QStackedBarSeries>
#include<QBarSet>
#include<QPieSeries>
#include<QScatterSeries>
#include<QPalette>
#include<QGridLayout>
#include <QVBarModelMapper>
#include<QBarSeries>
#include<QBarCategoryAxis>
#include<qglobal.h>
#include<vector>
#include <QCameraInfo>
#include<QCamera>
#include<QVideoWidget>
#include<QCameraViewfinder>
#include<QCameraImageCapture>
#include<QTableWidgetItem>
#include<user-win-dialog.h>
#include"creditsql.h"
#include <QSystemTrayIcon>
#include <QIcon>
#include<data-transfer-dialog.h>


QT_BEGIN_NAMESPACE
class QComboBox;
class QCheckBox;
class Ui_ThemeWidgetForm;
QT_END_NAMESPACE

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE

typedef QPair<QPointF, QString> Data;
typedef QList<Data> DataList;
typedef QList<DataList> DataTable;

QT_CHARTS_USE_NAMESPACE
class QToolButton;

namespace Ui {
class UIBasePlatformFrame;
}

class UIBasePlatformFrame : public QWidget
{
    Q_OBJECT

public:
    explicit UIBasePlatformFrame(QWidget *parent = 0);
    ~UIBasePlatformFrame();
    void initResize();
private:


    Ui::UIBasePlatformFrame *ui;

    //跑马灯---start
    int width;//QLable的长宽
    int hight;

    /*方式一：通过定时器实现 */
    QString text;//需要显示的文本
    QString d_text;//正在显示的文本
    QTimer* timer;//定时器

    int text_width;//需要显示的文本宽度
    int d_text_width;//正在显示的文本宽度
    int d_index;//填充文本索引
    int space_count;//填充空格计数
    //跑马灯---end
    QList<int> pixCharMain;
    QList<QToolButton *> btnsMain;

    QList<int> pixCharConfig;
    QList<QToolButton *> btnsConfig;

    QList<int> pixChar1;
    QList<QToolButton *> btnsLeft1;

    rtSql *m_ptrrtSql;
    sonSql *m_ptrSonSql;
    CreditSql *m_prtCreSql;
    QStringList m_lNames;

    void updateTable();
    void UpdateTable();
    void init_tableWidget_4();
    void updateTableWidget4();
    dlg_add m_dlgAddPer;
    dlg_add_user m_dlgAddUser;

    UserWinDialog userWinDialog;

    DataTransferDialog dataTransferDialog;


    void Tian(QList<PerInfo> l);
    void TianU(QList<UserInfo> u);
    //IP
    void showRightInfo();
    //托盘
    QSystemTrayIcon *stystemIcon;
private slots:
    void send();
    void dataTransferWin();
    void toTray();
    void display_text();
    void initForm();
    void buttonClick();
    void initLeftMain();
    void initLeftConfig();
    void initLeft1();
    void initPage4();
    void initPage5();
    void Time();

    void leftMainClick();
    void leftConfigClick();
    void leftClick1();



private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();
    void on_treeWidget_itemClicked(QTreeWidgetItem* item,int column);
    void showTime();
    void on_pushButton_3_clicked();
    void on_btn_add_clicked();
    void on_btn_delete_clicked();
    void on_btn_update_clicked();
    void on_btn_search_clicked();
    void on_btn_clear_clicked();
    void on_btn_clean_all_clicked();
    void on_btn_usearch_clicked();
    void on_btn_uclean_all_clicked();
    void on_btn_usim_clicked();
    void on_btn_clear_data_clicked();
    void on_btn_uadd_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

//    void on_tableWidget_cellDoubleClicked(int row, int column);
    void on_tableWidget_2_itemDoubleClicked(QTableWidgetItem *item);
    void on_pushButton_4_clicked();
    void on_treeWidget_2_itemClicked(QTreeWidgetItem *item, int column);
    void on_pushButton_5_clicked();
};

#endif // UIDEMO08_H
