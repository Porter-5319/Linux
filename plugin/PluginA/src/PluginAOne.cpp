#include "PluginAOne.h"

PluginAOne::PluginAOne(QObject* parent)
    :QObject (parent)
{

}

QString PluginAOne::output(const QString &message)
{
    qInfo() << message;
    return "";
}
