#ifndef CREDITSQL_H
#define CREDITSQL_H

#include <QObject>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QCoreApplication>
#include<QSqlError>
//定义因素结构体
struct CreInfo
{
  int id;
  QString group_id;
  QString group_name;
  QString leader_name;
  QString leader_gender;
  QString leader_politics;
  QString leader_phone;
  QString leader_unit;
  QString deputy_name;
  QString deputy_gender;
  QString deputy_politics;
  QString deputy_phone;
  QString deputy_unit;
  QString staffing;
  QString remark;
};

class CreditSql: public QObject
{
    Q_OBJECT
public:
    static CreditSql *creSql;
    static CreditSql *getinstance()
    {
        if(nullptr==creSql)
        {
            creSql=new CreditSql;
        }
        return creSql;

    };
    explicit CreditSql(QObject *parent = nullptr);
    void init();
    quint32 getPerCnt();
    //计算总数
    quint32 getTotal();


    QList<CreInfo> getPagePer(quint32 page,quint32 uiCnt);
    QList<CreInfo> PagePer(int currentPage);
    bool addPer(CreInfo info);
    bool addPer(QList<CreInfo> l);
    bool delPer(int id);
    bool UpdatePerInfo(CreInfo info);
    bool clearPerTable();
    void close();

    //按照姓名查找
    QList<CreInfo> searchByName(QString containt);
    //按照性别查找
    QList<CreInfo> searchByGender(int index);
signals:
private:
    QSqlDatabase cre_db;
};




#endif // CREDITSQL_H
