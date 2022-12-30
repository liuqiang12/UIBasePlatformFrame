#ifndef DBHELPER_H
#define DBHELPER_H
#include <QSqlDatabase>

class DBHelper
{
public:
    //向外界公开一个“获取唯一可用的对象”的成员函数
    static DBHelper* getInstance();
    //创建连接
    void createConnection();
    //关闭连接
    void destoryConnection();
    //创建一个 QSqlDatabase 的对象 db，之后要在构造函数中对 db 对象进行初始化
    QSqlDatabase db;

private:
    static DBHelper* Instance ;
    //因为是单例模式，所以让构造函数为 private，这样该类就不会被实例化
    DBHelper();
};

#endif // DBHELPER_H
