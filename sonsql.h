#ifndef SONSQL_H
#define SONSQL_H
#include <QObject>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QCoreApplication>
#include<QSqlError>
#include<qmap.h>
struct UserInfo
{
    int id;
    QString unit;
    QString job;
    QString name;
    QString gender;
    quint8 age;
    QString phone;
    QString address;
};
class sonSql : public QObject
{
    Q_OBJECT
public:
    static sonSql *ptrsonSql;
    static sonSql *getinstance()
    {
        if(nullptr==ptrsonSql)
        {
            ptrsonSql=new sonSql;
        }
        return ptrsonSql;
    };
public:
    explicit sonSql(QObject *parent = nullptr);

    //初始化数据库，把数据库打开
    void init();
    //查询所有人员数量
    quint32 getUserCnt();
    //查询第几页人员数据  从第0页开始
    QList<UserInfo> getPageUser(quint32 page,quint32 uiCnt);
    //增加人员
    bool addUser(UserInfo info);
    //因为速度比较慢，所以要改写一下，
    bool addUser(QList<UserInfo> l);
    //删除人员
    bool delUser(int id);
    //修改人员信息
    bool UpdateUserInfo(UserInfo info);
    //清空表
    bool clearUserTable();
    //关闭数据库
    void close();
    //按照姓名查找
    QList<UserInfo> searchByName(QString containt);
    //按照性别查找
    QList<UserInfo> searchByGender(int index);
    //按照年龄、性别查找
    QList<UserInfo> searchByNG(QString containt,int index);

    QList<int> getGenderCnt();
    QMap<QString,int> getJobCnt();
    QMap<int,int> getAgeCnt();
signals:
private:
    QSqlDatabase son_db;

};

#endif // SONSQL_H
