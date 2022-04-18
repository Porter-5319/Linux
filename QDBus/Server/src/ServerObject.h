#ifndef SERVEROBJECT_H
#define SERVEROBJECT_H

#include <QObject>
#include <QDBusContext>
#include <QDBusConnection>

class ServerObject : public QObject
{
    Q_OBJECT
    //定义Interface名称为com.liujun.server1.object1
    Q_CLASSINFO("D-Bus Interface", "com.liujun.server1.object1")
public:
    explicit ServerObject(QObject *parent = nullptr);

public slots:
    // 定义接口，供前台访问
    QString getName();
    void setName(QString name);

private:
    QString m_Name;
};

#endif // SERVEROBJECT_H
