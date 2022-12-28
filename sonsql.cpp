#include "sonsql.h"
sonSql * sonSql::ptrsonSql=nullptr;
sonSql::sonSql(QObject *parent) : QObject(parent)
{
    init();
}
void sonSql::close()
{
    QString connection;
    connection = son_db.connectionName();
    son_db.close();
    son_db = QSqlDatabase();
    son_db.removeDatabase(connection);
}

void sonSql::init()
{
    close();
    if(QSqlDatabase::drivers().isEmpty())
        qDebug()<<"No database drivers found";
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    son_db = QSqlDatabase::database("qt_sql_default_connection");
    else
    son_db = QSqlDatabase::addDatabase("QSQLITE");
    son_db.setDatabaseName("E:\\WorkSpace\\2022.12.26V20221226\\rtdata.db");
    if(!son_db.open())
        qDebug()<<"db not open";
}

quint32 sonSql::getUserCnt()
{
    QSqlQuery sql(son_db);
    sql.exec("select count(id) from user");
    quint32 uiCnt=0;
    while (sql.next())
    {
       uiCnt=sql.value(0).toUInt();
    }
    return uiCnt;
}

QList<int> sonSql::getGenderCnt()
{
    QSqlQuery sql(son_db);
    QList<int> l;
    sql.exec("select count(name) from user group by gender");
    quint32 uiCnt=0;
//    qDebug()<<sql.size();
    while (sql.next())
    {
       uiCnt=sql.value(0).toUInt();
       l.push_back(uiCnt);
    }
    return l;
}

QMap<int,int> sonSql::getAgeCnt()
{
    QSqlQuery sql(son_db);
    QMap<int,int> map;
    sql.exec("select distinct(age),count(age) from user group  by age");
    while (sql.next())
    {
        map.insert(sql.value(0).toInt(),sql.value(1).toInt());
    }
    return map;
}
QMap<QString,int> sonSql::getJobCnt()
{
    QSqlQuery sql(son_db);
    QMap<QString,int> map;
    sql.exec("select job,count(job) from user group by job;");
    while (sql.next())
    {
        map.insert(sql.value(0).toString(),sql.value(1).toInt());
    }
    return map;
}

QList<UserInfo> sonSql::getPageUser(quint32 page, quint32 uiCnt)
{
    QList<UserInfo> l;
    QSqlQuery sql(son_db);
    QString strSql=QString("select * from user order by id limit '%1' offset '%2'").
            arg(uiCnt).
            arg(page*uiCnt);
    sql.exec(strSql);
    UserInfo info;
    while (sql.next())
    {
       info.id=sql.value(0).toInt();
       info.unit=sql.value(1).toString();
       info.job=sql.value(2).toString();
       info.name=sql.value(3).toString();
       info.gender=sql.value(4).toString();
       info.age=sql.value(5).toUInt();
       info.phone=sql.value(6).toString();
       info.address=sql.value(7).toString();
       l.push_back(info);
    }
    return l;
}

bool sonSql::addUser(UserInfo info)
{
    QSqlQuery sql(son_db);
    QString strSql=QString("insert into user values (null,'%1','%2','%3','%4',%5,'%6','%7')").
            arg(info.unit).
            arg(info.job).
            arg(info.name).
            arg(info.gender).
            arg(info.age).
            arg(info.phone).
            arg(info.address);
    return sql.exec(strSql);
}

bool sonSql::addUser(QList<UserInfo> l)
{
    QSqlQuery sql(son_db);
    son_db.transaction();
    for(auto info:l)
    {
        QString strSql=QString("insert into user values (null,'%1','%2','%3','%4',%5,'%6','%7')").
                arg(info.unit).
                arg(info.job).
                arg(info.name).
                arg(info.gender).
                arg(info.age).
                arg(info.phone).
                arg(info.address);
        sql.exec(strSql);
    }

}

bool sonSql::delUser(int id)
{
    QSqlQuery sql(son_db);
    return sql.exec(QString("delete from user where id=%1").arg(id));
}

bool sonSql::UpdateUserInfo(UserInfo info)
{
    QSqlQuery sql(son_db);
    int temp=info.id;
    QString strSql=QString("update user set unit = '%1',job='%2',name='%3',gender='%4',age=%5,phone ='%6',address='%7' where id=%8").
            arg(info.unit).
            arg(info.job).
            arg(info.name).
            arg(info.gender).
            arg(info.age).
            arg(info.phone).
            arg(info.address).
            arg(temp);
    bool ret =sql.exec(strSql);
    return ret;
}

bool sonSql::clearUserTable()
{
    QSqlQuery sql(son_db);
    sql.exec("delete from user");
    return sql.exec("delete from sqlite_sequence where name='user'");
}

QList<UserInfo> sonSql::searchByName(QString containt)
{
    UserInfo info;
    QList<UserInfo> l;
    QSqlQuery sql(son_db);

    sql.exec(QString("select * from user where name like '%%1%' order by id").arg(containt));
    while (sql.next())
    {
       info.id=sql.value(0).toInt();
       info.unit=sql.value(1).toString();
       info.job=sql.value(2).toString();
       info.name=sql.value(3).toString();
       info.gender=sql.value(4).toString();
       info.age=sql.value(5).toUInt();
       info.phone=sql.value(6).toString();
       info.address=sql.value(7).toString();
       l.push_back(info);
    }
    return l;
}








