#ifndef PLUGININTERFACEA_H
#define PLUGININTERFACEA_H

#include <QString>
#include <QtPlugin>
#include <QDebug>

class PluginInterfaceA
{
public:
    PluginInterfaceA();
    virtual ~PluginInterfaceA();
    virtual QString output(const QString &message) = 0;
};

#define PluginInterfaceA_iid "Plugin.PluginA.PluginInterfaceA"   // 唯一标识符
Q_DECLARE_INTERFACE(PluginInterfaceA, PluginInterfaceA_iid)

#endif // PLUGININTERFACEA_H
