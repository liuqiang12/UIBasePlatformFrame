#include "UIBasePlatformFrame.h"
#include "appinit.h"
#include <QApplication>
#include <QTextCodec>
#include <QFile>
#include <QMenu>
#include <QProcess>
#include <QSystemTrayIcon>
#include <QtGlobal>
#include <QDesktopServices>
#include <QUrl>
#include<QSettings>
#include<QFileInfo>
#include<QDir>
#include<DbHelper.h>

#include "autorun.h"   //开机自动运行
QSystemTrayIcon *trayIcon;

// 打开点击事件处理器
void handleOpen(){
    qDebug(">> Open button clicked!");
    QDesktopServices::openUrl(QUrl("http://www.baidu.com"));
}

void handleQuit(){
    trayIcon->hide();
    QCoreApplication::quit();
}






/**
 * http://www.fontawesome.com.cn/cheatsheet/
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
#if _MSC_VER
    QTextCodec *codec = QTextCodec::codecForName("gbk");
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
#endif
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
#endif
    autoRun();//设置开机自动运行

//    QFile fread;
//    fread.setFileName(":/qss/psblack.css");
//    fread.open(QIODevice::ReadOnly);
//    QString strQss=fread.readAll();
//    this->setStyleSheet(strQss);
//    fread.close();




//    QFile file(":/qss/psblack.css");
//    if (file.open(QFile::ReadOnly)) {
//        QString qss = QLatin1String(file.readAll());
//        QString paletteColor = qss.mid(20, 7);
//        qApp->setPalette(QPalette(QColor(paletteColor)));
//        qApp->setStyleSheet(qss);
//        file.close();

////        QFile fread;
////        fread.setFileName(":/qss/psblack.css");
////        fread.open(QIODevice::ReadOnly);
////        QString strQss=fread.readAll();
////        this->setStyleSheet(strQss);
////        fread.close();

//    }

   //创建右键菜单
//   QMenu menu;

//   QAction openAct("打开业务系统");
//   QAction quitAct("退出");

//   menu.addAction(&openAct);
//   menu.addAction(&quitAct);
//   // 菜单绑定事件回调
//   QObject::connect(&quitAct, &QAction::triggered, qApp, &handleQuit);
//   QObject::connect(&openAct, &QAction::triggered, qApp, &handleOpen);



//   // 加载图标
//   QPixmap oPixmap(32, 32);
//   oPixmap.load(":/image/icon.png");
//   QIcon qIcon(oPixmap);

//   // 创建并配置状态栏icon
//   trayIcon = new QSystemTrayIcon(qIcon);
//   trayIcon->setContextMenu(&menu);
//   // 给托盘设置ICON
//   trayIcon->setIcon(QIcon(":/image/wx.png"));
//    // 设置托盘鼠标悬浮显示内容
//   trayIcon->setToolTip("接收处置综合服务保障");
//   trayIcon->setVisible(true);

   // 创建两个菜单事件
//   QAction *actShowWindow = new QAction("打开主界面",this);
//   connect(actShowWindow,&QAction::triggered,[this]{this->show();});
//   QAction *actExit = new QAction("退出",this);
//   connect(actExit,&QAction::triggered,[this]{this->close();});





    a.setFont(QFont("Microsoft Yahei", 9));
    AppInit::Instance()->start();

    UIBasePlatformFrame w;
    /* 设置背景图片 */

    w.show();


    return a.exec();
}

