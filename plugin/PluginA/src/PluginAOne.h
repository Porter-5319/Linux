#ifndef PLUGINAONE_H
#define PLUGINAONE_H

#include <QObject>
#include <PluginInterfaceA.h>

#define JSON_PLUGINA_ONE "plugina_one.json"

class PluginAOne : public QObject, public PluginInterfaceA
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PluginInterfaceA_iid FILE JSON_PLUGINA_ONE)
    Q_INTERFACES(PluginInterfaceA)
public:
    explicit PluginAOne(QObject* parent = nullptr);
    virtual  QString output(const QString &message) Q_DECL_OVERRIDE;
};

#endif // PLUGINAONE_H
