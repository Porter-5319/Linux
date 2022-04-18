#include <iostream>
#include <QDBusConnection>
#include <QDebug>
#include <QCoreApplication>

#include "ServerObject.h"

// 注册服务
void registerServer1(ServerObject* obj)
{
    // 建立连接
    QDBusConnection con = QDBusConnection::sessionBus();
    if(!con.isConnected())
        return;

    // 注册服务
    if(!con.registerService("com.liujun.server1")){
        qInfo() << "注册服务 com.liujun.server1 失败";
        return;
    }

    // 注册对象
    con.registerObject("/com/liujun/server1",obj,QDBusConnection::RegisterOption::ExportAllSlots);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerObject obj;
    registerServer1(&obj);

    return a.exec();
}
