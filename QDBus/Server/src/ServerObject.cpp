#include "ServerObject.h"
#include <QDebug>

ServerObject::ServerObject(QObject *parent) : QObject(parent)
  , m_Name("uos")
{
    QDBusConnection::sessionBus().connect("","/com/liujun/server1","com.liujun.server1.object1","setName",this,SLOT(setName(QString)));
}

QString ServerObject::getName()
{
    qInfo() << "getName ************* ";
    return m_Name;
}
void ServerObject::setName(QString name)
{
    qInfo() << " ******* " << name;
    m_Name = name;
}
