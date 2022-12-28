#include "creditsql.h"
#include<QFile>
CreditSql * CreditSql::creSql=nullptr;
CreditSql::CreditSql(QObject *parent) : QObject(parent)
{
    init();
}

void CreditSql::init()
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

quint32 CreditSql::getPerCnt()
{
    QSqlQuery sql(rt_db);
    sql.exec("select count(id) from creditinfo ");
    quint32 uiCnt=0;
    while (sql.next())
    {
       uiCnt=sql.value(0).toUInt();
    }
    return uiCnt;
}

QList<CreInfo> CreditSql::getPagePer(quint32 page, quint32 uiCnt)
{
    QList<CreInfo> l;
    QSqlQuery sql(rt_db);
    QString strSql=QString("select * from rtinfo order by id limit '%1' offset '%2'").
            arg(uiCnt).
            arg(page*uiCnt);
    sql.exec(strSql);
    CreInfo info;
    while (sql.next())
    {
       info.id=sql.value(0).toInt();
       info.group_id=sql.value(1).toString();
       info.group_name=sql.value(2).toString();
       info.leader_name=sql.value(3).toString();
       info.leader_gender=sql.value(4).toString();
       info.leader_politics=sql.value(5).toString();
       info.leader_phone=sql.value(6).toString();
       info.leader_unit=sql.value(7).toString();
       info.deputy_name=sql.value(8).toString();
       info.deputy_gender=sql.value(9).toString();
       info.deputy_politics=sql.value(10).toString();
       info.deputy_phone=sql.value(11).toString();
       info.deputy_unit=sql.value(12).toString();
       info.staffing=sql.value(13).toString();
       info.remark=sql.value(14).toString();
       l.push_back(info);
    }
    return l;
}

void CreditSql::close()
{
    QString connection;
    connection = rt_db.connectionName();
    rt_db.close();
    rt_db = QSqlDatabase();
    rt_db.removeDatabase(connection);
}
