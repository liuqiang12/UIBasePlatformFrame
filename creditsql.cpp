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
    cre_db = QSqlDatabase::database("qt_sql_default_connection");
    else
    cre_db = QSqlDatabase::addDatabase("QSQLITE","creditinfo");
    cre_db.setDatabaseName("E:\\WorkSpace\\UIBasePlatformFrame\\rtdata.db");
    if(!cre_db.open())
        qDebug()<<"db not open";
}

quint32 CreditSql::getPerCnt()
{
    QSqlQuery sql(cre_db);
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
    QSqlQuery sql(cre_db);
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

bool CreditSql::addPer(CreInfo info)
{
    QSqlQuery sql(cre_db);
    QString strSql=QString("insert into creditinfo values (null,'%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14')").
            arg(info.group_id).
            arg(info.group_name).
            arg(info.leader_name).
            arg(info.leader_gender).
            arg(info.leader_politics).
            arg(info.leader_phone).
            arg(info.leader_unit).
            arg(info.deputy_name).
            arg(info.deputy_gender).
            arg(info.deputy_politics).
            arg(info.deputy_phone).
            arg(info.deputy_unit).
            arg(info.staffing).
            arg(info.remark);

    return sql.exec(strSql);
}

bool CreditSql::addPer(QList<CreInfo> l)
{
    QSqlQuery sql(cre_db);
    cre_db.transaction();
    for(auto info:l)
    {
        QString strSql=QString("insert into creditinfo values (null,'%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14')").
                arg(info.group_id).
                arg(info.group_name).
                arg(info.leader_name).
                arg(info.leader_gender).
                arg(info.leader_politics).
                arg(info.leader_phone).
                arg(info.leader_unit).
                arg(info.deputy_name).
                arg(info.deputy_gender).
                arg(info.deputy_politics).
                arg(info.deputy_phone).
                arg(info.deputy_unit).
                arg(info.staffing).
                arg(info.remark);
        sql.exec(strSql);
    }
    cre_db.commit();
    return true;
}

bool CreditSql::delPer(int id)
{
    QSqlQuery sql(cre_db);
    return sql.exec(QString("delete from creditinfo where id=%1").arg(id));
}

void CreditSql::close()
{
    QString connection;
    connection = cre_db.connectionName();
    cre_db.close();
    cre_db = QSqlDatabase();
    cre_db.removeDatabase(connection);
}
