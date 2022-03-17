#include "PluginBOne.h"

PluginBOne::PluginBOne(QObject* parent)
    :QObject (parent)
{

}

QString PluginBOne::output(const QString &message)
{
    qInfo() << "我是pluginB-one" << message;
    return "";
}
