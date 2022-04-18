#include "DBusClient.h"

DBusClient::DBusClient(QObject *parent) : QObject(parent)
{

}

void DBusClient::testDBusInterface()
{
    // 创建 dbus接口  com.liujun.server1.object1
    QDBusInterface interface("com.liujun.server1", "/com/liujun/server1",
                                 "com.liujun.server1.object1",
                                 QDBusConnection::sessionBus());
    if(!interface.isValid()){
        qInfo() << "interface *********************** ";
    }

    // 调用
    interface.call("setName","LIUJUN");
    QDBusReply<QString> reply = interface.call("getName");
    if(reply.isValid()){
        qInfo() << "Get Name form server ****QDBusInterface**** " << reply.value();
    }else{
        qInfo() << reply.error().message();
    }
}

void DBusClient::testCreateMethodCall()
{
    //    QDBusMessage message_set = QDBusMessage::createMethodCall("com.liujun.server1","/com/liujun/server1","com.liujun.server1.object1","setName");
    //    // 准备参数
    //    QList<QVariant> args;
    //    args << "PYTHON_MAN";
    //    message_set.setArguments(args);
    //    QDBusConnection::sessionBus().call(message_set);

    QDBusMessage message_get = QDBusMessage::createMethodCall("com.liujun.server1","/com/liujun/server1","com.liujun.server1.object1","getName");
    QDBusReply<QString> reply = QDBusConnection::sessionBus().call(message_get);
    if(reply.isValid()){
        qInfo() << "Get Name form server ****QDBusMessage**** " << reply.value();
    }else{
        qInfo() << reply.error().message();
    }
}

void DBusClient::testCreateMethodCall1()
{
    QDBusMessage message_get = QDBusMessage::createMethodCall("com.liujun.server1","/com/liujun/server1","com.liujun.server1.object1","getName");
    QDBusMessage response = QDBusConnection::sessionBus().call(message_get);
    if(response.type() == QDBusMessage::ReplyMessage && message_get.arguments().size() > 0){
        qInfo() << "Get Name form server ****QDBusMessage**** " << message_get.arguments().takeFirst().toString();
    }else{
        qInfo() << "没有获取到消息";
    }
}

void DBusClient::testCreateSignals()
{
    QDBusMessage msg = QDBusMessage::createSignal("/com/liujun/server1","com.liujun.server1.object1","setName");
    msg << QString("hello signals");
    if(QDBusConnection::sessionBus().send(msg)){
        qInfo() << "success";
    }
}
