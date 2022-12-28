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
    QList<CreInfo> getPagePer(quint32 page,quint32 uiCnt);
    //增加人员
    bool addPer(CreInfo info);
    //因为速度比较慢，所以要改写一下，
    bool addPer(QList<CreInfo> l);
    //删除人员
    bool delPer(int id);
    //修改人员信息
    bool UpdatePerInfo(CreInfo info);
    //查询人员是否存在
//    bool isExit(QString strPer);
    //清空表
    bool clearPerTable();
    //关闭数据库
    void close();
    //按照姓名查找
    QList<CreInfo> searchByName(QString containt);
    //按照性别查找
    QList<CreInfo> searchByGender(int index);
    //按照年龄、性别查找
    QList<CreInfo> searchByNG(QString containt,int index);
signals:
private:
    QSqlDatabase rt_db;
};




#endif // CREDITSQL_H
