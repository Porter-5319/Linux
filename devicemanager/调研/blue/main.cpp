#include <QCoreApplication>
#include <QDebug>

#include "BTTool.h"
#include "DeviceBluetooth.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<DeviceBluetooth*> lstBlue;
    BTTool::getConnectedBt(lstBlue);

    //
    foreach(DeviceBluetooth* blue,lstBlue){
        qInfo() << "逻辑传输类型 : " << blue->logicalTrans();
        qInfo() << "链接模式 : " << blue->linkMode();
        qInfo() << "物理地址 : " << blue->addr();
        qInfo() << "蓝牙设备名称 : " << BTTool::getConnectBtName(blue->addr());
        qInfo() << "时钟偏移 : " << BTTool::getConnectBtClkoff(blue->addr());
    }
    return a.exec();
}
