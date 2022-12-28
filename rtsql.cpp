#include "rtsql.h"
#include<QFile>
rtSql * rtSql::ptrrtSql=nullptr;
rtSql::rtSql(QObject *parent) : QObject(parent)
{
    init();
}
void rtSql::close()
{
    QString connection;
    connection = rt_db.connectionName();
    rt_db.close();
    rt_db = QSqlDatabase();
    rt_db.removeDatabase(connection);
}

void rtSql::init()
{
    close();
    if(QSqlDatabase::drivers().isEmpty())
     qDebug()<<"No database drivers found";
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    rt_db = QSqlDatabase::database("qt_sql_default_connection");
    else
    rt_db = QSqlDatabase::addDatabase("QSQLITE");
    rt_db.setDatabaseName("E:\\2022\\2022.12.27\\2022.12.26V20221226\\rtdata.db");
    if(!rt_db.open())
        qDebug()<<"db not open";
}

bool rtSql::addPer(PerInfo info)
{
    QSqlQuery sql(rt_db);
    QString strSql=QString("insert into rtinfo values (null,'%1','%2',%3,'%4','%5','%6','%7')").
            arg(info.name).
            arg(info.gender).
            arg(info.age).
            arg(info.school).
            arg(info.time).
            arg(info.phone).
            arg(info.email);

    return sql.exec(strSql);
}

bool rtSql::addPer(QList<PerInfo> l)
{
    QSqlQuery sql(rt_db);
    rt_db.transaction();
    for(auto info:l)
    {
        QString strSql=QString("insert into rtinfo values (null,'%1','%2',%3,'%4','%5','%6','%7')").
                arg(info.name).
                arg(info.gender).
                arg(info.age).
                arg(info.school).
                arg(info.time).
                arg(info.phone).
                arg(info.email);
        sql.exec(strSql);
    }
    rt_db.commit();
    return true;
}

quint32 rtSql::getPerCnt()
{
    QSqlQuery sql(rt_db);
    sql.exec("select count(id) from rtinfo");
    quint32 uiCnt=0;
    while (sql.next())
    {
       uiCnt=sql.value(0).toUInt();
    }
    return uiCnt;
}

QList<PerInfo> rtSql::getPagePer(quint32 page, quint32 uiCnt)
{
    QList<PerInfo> l;
    QSqlQuery sql(rt_db);
    QString strSql=QString("select * from rtinfo order by id limit '%1' offset '%2'").
            arg(uiCnt).
            arg(page*uiCnt);
    sql.exec(strSql);
    PerInfo info;
    while (sql.next())
    {
       info.id=sql.value(0).toInt();
       info.name=sql.value(1).toString();
       info.gender=sql.value(2).toString();
       info.age=sql.value(3).toInt();
       info.school=sql.value(4).toString();
       info.time=sql.value(5).toString();
       info.phone=sql.value(6).toString();
       info.email=sql.value(7).toString();
       l.push_back(info);
    }
    return l;
}

bool rtSql::delPer(int id)
{
    QSqlQuery sql(rt_db);
    return sql.exec(QString("delete from rtinfo where id=%1").arg(id));
}

bool rtSql::clearPerTable()
{
    QSqlQuery sql(rt_db);
    sql.exec("delete from rtinfo");
    return sql.exec("delete from sqlite_sequence where name='rtinfo'");
}

bool rtSql::UpdatePerInfo(PerInfo info)
{
    QSqlQuery sql(rt_db);
    int temp=info.id;
    QString strSql=QString("update rtinfo set name = '%1',gender='%2',age=%3,school='%4',time='%5',phone ='%6',email='%7' where id=%8").
            arg(info.name).
            arg(info.gender).
            arg(info.age).
            arg(info.school).
            arg(info.time).
            arg(info.phone).
            arg(info.email).
            arg(temp);
    bool ret =sql.exec(strSql);
    return ret;
}

QList<PerInfo> rtSql::searchByName(QString containt)
{
    PerInfo info;
    QList<PerInfo> l;
    QSqlQuery sql(rt_db);

    sql.exec(QString("select * from rtinfo where name like '%%1%' order by id").arg(containt));
    while (sql.next())
    {
       info.id=sql.value(0).toInt();
       info.name=sql.value(1).toString();
       info.gender=sql.value(2).toString();
       info.age=sql.value(3).toInt();
       info.school=sql.value(4).toString();
       info.time=sql.value(5).toString();
       info.phone=sql.value(6).toString();
       info.email=sql.value(7).toString();
       l.push_back(info);
    }
    return l;
}

QList<PerInfo> rtSql::searchByGender(int index)
{
    PerInfo info;
    QList<PerInfo> l;
    QSqlQuery sql(rt_db);
    QString gender;
    if (index==0)
    {
        gender="男";
    }else if (index==1)
    {
        gender="女";
    }
    sql.exec(QString("select * from rtinfo where gender='%1' order by id").arg(gender));
    while (sql.next())
    {
       info.id=sql.value(0).toInt();
       info.name=sql.value(1).toString();
       info.gender=sql.value(2).toString();
       info.age=sql.value(3).toInt();
       info.school=sql.value(4).toString();
       info.time=sql.value(5).toString();
       info.phone=sql.value(6).toString();
       info.email=sql.value(7).toString();
       l.push_back(info);
    }
    return l;
}

QList<PerInfo> rtSql::searchByNG(QString containt, int index)
{
    PerInfo info;
    QList<PerInfo> l;
    QSqlQuery sql(rt_db);
    QString gender;
    if (index==0)
    {
        gender="男";
    }else if (index==1)
    {
        gender="女";
    }
    sql.exec(QString("select * from rtinfo where name like '%%1%' and gender='%2' order by id").arg(containt).arg(gender));
    while (sql.next())
    {
       info.id=sql.value(0).toInt();
       info.name=sql.value(1).toString();
       info.gender=sql.value(2).toString();
       info.age=sql.value(3).toInt();
       info.school=sql.value(4).toString();
       info.time=sql.value(5).toString();
       info.phone=sql.value(6).toString();
       info.email=sql.value(7).toString();
       l.push_back(info);
    }
    return l;
}

















