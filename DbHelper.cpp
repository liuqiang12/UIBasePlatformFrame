#include "DbHelper.h"


DBHelper* DBHelper::Instance=0;

DBHelper* DBHelper::getInstance()
{
    if(Instance==0)
        Instance =new DBHelper();
    return Instance;
}

DBHelper::DBHelper()
{
    //在构造函数中对 db 对象进行初始化
    db = QSqlDatabase::addDatabase("QSQLITE");
}

void DBHelper::createConnection()
{
    //我们需要指定数据库文件
    db.setDatabaseName("E:\\WorkSpace\\UIBasePlatformFrame\\rtdata.db");
    db.open();
}
/**
 * @brief DBHelper::destoryConnection
 * @details 关闭连接
 */
void DBHelper::destoryConnection()
{
    db.close();
    db.removeDatabase("E:\\WorkSpace\\UIBasePlatformFrame\\rtdata.db");
}
