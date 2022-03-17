#ifndef PLUGINBTWO_H
#define PLUGINBTWO_H

#include <QObject>
#include "PluginB/PluginInterfaceB.h"

#define JSON_PLUGINB_TWO "../pluginb_two.json"

class PluginBTwo : public QObject, public PluginInterfaceB
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PluginInterfaceB_iid FILE JSON_PLUGINB_TWO)
    Q_INTERFACES(PluginInterfaceB)
public:
    explicit PluginBTwo(QObject* parent = nullptr);
    virtual  QString output(const QString &message) Q_DECL_OVERRIDE;
};

#endif // PLUGINBTWO_H
