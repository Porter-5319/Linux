#ifndef BTTOOL_H
#define BTTOOL_H

#include <QString>
#include <QDebug>
#include <QList>

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>

class DeviceBluetooth;

class BTTool
{
public:
    BTTool();

    /**
     * @brief getConnectedBt 获取蓝牙设备，创建对象
     * @return
     */
    static int getConnectedBt(QList<DeviceBluetooth*>& lstBlue);

    /**
     * @brief getConnectBtName 根据物理地址获取蓝牙设备的名称
     * @param dd 蓝牙适配器的句柄
     * @param addr 设备的物理地址
     * @return
     */
    static QString getConnectBtName(const QString& addr);

    /**
     * @brief getConnectBtClkoff 获取时钟偏移
     * @param addr 设备的物理地址
     * @return
     */
    static QString getConnectBtClkoff(const QString& addr);

private:
    /**
     * @brief type2str 获取主从角色字符串
     * @param type 主从角色的标识码
     * @return
     */
    static QString type2str(unsigned short type);
};

#endif // BTTOOL_H
