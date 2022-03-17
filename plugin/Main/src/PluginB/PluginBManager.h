#ifndef PLUGINBMANAGER_H
#define PLUGINBMANAGER_H

#include <mutex>
#include <QObject>
#include "PluginInterfaceB.h"

class PluginBManager : public QObject
{
public:
    inline static PluginBManager *getInstance()
    {
        // 利用原子变量解决，单例模式造成的内存泄露
        PluginBManager *sin = s_Instance.load();

        if (!sin) {
            // std::lock_guard 自动加锁解锁
            std::lock_guard<std::mutex> lock(m_mutex);
            sin = s_Instance.load();

            if (!sin) {
                sin = new PluginBManager();
                s_Instance.store(sin);
            }
        }

        return sin;
    }

    /**
     * @brief loadAllPlugins 加载所有插件
     */
    void loadAllPlugins();

protected:
    explicit PluginBManager(QObject* parent = nullptr);
    virtual ~PluginBManager();

private:
    static std::atomic<PluginBManager *> s_Instance;
    static std::mutex                         m_mutex;
};

#endif // PLUGINBMANAGER_H
