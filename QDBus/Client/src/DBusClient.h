#ifndef DBUSCLIENT_H
#define DBUSCLIENT_H

#include <QObject>
#include <QDBusConnection>
#include <QDBusReply>
#include <QDBusInterface>
#include <QDebug>

class DBusClient : public QObject
{
    Q_OBJECT
public:
    explicit DBusClient(QObject *parent = nullptr);


    // 调用后台接口
    void testDBusInterface();
    void testCreateMethodCall();
    void testCreateMethodCall1();

    // 向后台发送消息
    void testCreateSignals();
};

#endif // DBUSCLIENT_H
