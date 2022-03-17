#ifndef PLUGINBONE_H
#define PLUGINBONE_H

#include <QObject>
#include "PluginB/PluginInterfaceB.h"

#define JSON_PLUGINB_ONE "../pluginb_one.json"

class PluginBOne : public QObject, public PluginInterfaceB
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PluginInterfaceB_iid FILE JSON_PLUGINB_ONE)
    Q_INTERFACES(PluginInterfaceB)
public:
    explicit PluginBOne(QObject* parent = nullptr);
    virtual  QString output(const QString &message) Q_DECL_OVERRIDE;
};

#endif // PLUGINBONE_H
