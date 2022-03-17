#ifndef PLUGININTERFACEB_H
#define PLUGININTERFACEB_H

#include <QString>
#include <QtPlugin>
#include <QDebug>

class PluginInterfaceB
{
public:
    PluginInterfaceB();
    virtual ~PluginInterfaceB();
    virtual QString output(const QString &message) = 0;
};

#define PluginInterfaceB_iid "Plugin.PluginB.PluginInterfaceB"   // 唯一标识符
Q_DECLARE_INTERFACE(PluginInterfaceB, PluginInterfaceB_iid)

#endif // PLUGININTERFACEB_H
