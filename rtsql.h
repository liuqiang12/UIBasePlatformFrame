#ifndef RTSQL_H
#define RTSQL_H

#include <QObject>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QCoreApplication>
#include<QSqlError>
//定义人员因素的结构体
struct PerInfo
{
  int id;
  QString name;
  QString gender;
  quint8 age;
  QString school;
  QString time;
  QString phone;
  QString email;

};
class rtSql : public QObject
{
    Q_OBJECT
public:
    static rtSql *ptrrtSql;
    static rtSql *getinstance()
    {
        if(nullptr==ptrrtSql)
        {
            ptrrtSql=new rtSql;
        }
        return ptrrtSql;

    };
    explicit rtSql(QObject *parent = nullptr);
    //初始化数据库，把数据库打开
    void init();
    //查询所有人员数量
    quint32 getPerCnt();
    //查询第几页人员数据  从第0页开始
    QList<PerInfo> getPagePer(quint32 page,quint32 uiCnt);
    //增加人员
    bool addPer(PerInfo info);
    //因为速度比较慢，所以要改写一下，
    bool addPer(QList<PerInfo> l);
    //删除人员
    bool delPer(int id);
    //修改人员信息
    bool UpdatePerInfo(PerInfo info);
    //查询人员是否存在
//    bool isExit(QString strPer);
    //清空表
    bool clearPerTable();
    //关闭数据库
    void close();
    //按照姓名查找
    QList<PerInfo> searchByName(QString containt);
    //按照性别查找
    QList<PerInfo> searchByGender(int index);
    //按照年龄、性别查找
    QList<PerInfo> searchByNG(QString containt,int index);
signals:
private:
    QSqlDatabase rt_db;
};

#endif // RTSQL_H
