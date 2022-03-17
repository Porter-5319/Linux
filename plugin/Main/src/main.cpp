#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <QPluginLoader>
#include <QJsonArray>

#include "PluginA/PluginInterfaceA.h"
#include "PluginB/PluginBManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    QDir path = QDir(qApp->applicationDirPath());
//    path.cd("pluginsA");
//    foreach (QFileInfo info, path.entryInfoList(QDir::Files | QDir::NoDotAndDotDot))
//    {
//        QPluginLoader pluginLoader(info.absoluteFilePath());
//        QObject *plugin = pluginLoader.instance();
//        if (plugin)
//        {
//            // 获取元数据（名称、版本、依赖）
//            QJsonObject json = pluginLoader.metaData().value("MetaData").toObject();
//            qInfo() << "********** MetaData **********";
//            qInfo() << json.value("author").toVariant();
//            qInfo() << json.value("date").toVariant();
//            qInfo() << json.value("name").toVariant();
//            qInfo() << json.value("version").toVariant();
//            qInfo() << json.value("dependencies").toArray().toVariantList();

//            //访问感兴趣的接口
//            PluginInterfaceA *app = qobject_cast<PluginInterfaceA*>(plugin);
//            if (app)
//            {
//                app->output("i am a plugin");
//            }

//        }
//    }

    PluginBManager::getInstance()->loadAllPlugins();
    return a.exec();
}
