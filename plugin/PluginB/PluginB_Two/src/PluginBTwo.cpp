#include "PluginBTwo.h"

PluginBTwo::PluginBTwo(QObject* parent)
    :QObject (parent)
{

}

QString PluginBTwo::output(const QString &message)
{
    qInfo() << "我是pluginB-two 我做过修改 " << message;
    return "";
}
