#include<QDir>
#include <QCoreApplication>
#include <QPluginLoader>
#include <QJsonArray>
#include "PluginBManager.h"
#include "PluginInterfaceB.h"

// 以下这个问题可以避免单例的内存泄露问题
std::atomic<PluginBManager *> PluginBManager::s_Instance;
std::mutex PluginBManager::m_mutex;

PluginBManager::PluginBManager(QObject* parent)
    :QObject (parent)
{
}

PluginBManager::~PluginBManager()
{

}

void PluginBManager::loadAllPlugins()
{
    QDir path = QDir(qApp->applicationDirPath());
    path.cd("pluginsB");

    foreach (QFileInfo info, path.entryInfoList(QDir::Files | QDir::NoDotAndDotDot))
    {
        QPluginLoader pluginLoader(info.absoluteFilePath());
        QObject *plugin = pluginLoader.instance();
        if (plugin)
        {
            // 获取元数据（名称、版本、依赖）
            QJsonObject json = pluginLoader.metaData().value("MetaData").toObject();
            qInfo() << "********** MetaData **********";
            qInfo() << json.value("author").toVariant();
            qInfo() << json.value("date").toVariant();
            qInfo() << json.value("name").toVariant();
            qInfo() << json.value("version").toVariant();
            qInfo() << json.value("dependencies").toArray().toVariantList();

            //访问感兴趣的接口
            PluginInterfaceB *app = qobject_cast<PluginInterfaceB*>(plugin);
            if (app)
            {
                app->output("i am a plugin");
            }

        }
    }
}
