#include "DeviceBluetooth.h"

DeviceBluetooth::DeviceBluetooth(QObject *parent) : QObject(parent)
{

}

void DeviceBluetooth::setHandle(int handle)
{
    m_Handle = handle;
}
void DeviceBluetooth::setAddr(const QString& addr)
{
    m_Addr = addr;
}
void DeviceBluetooth::setLogicalTrans(const QString& logicalTrans)
{
    m_LogicalTrans = logicalTrans;
}
void DeviceBluetooth::setIsOut(bool out)
{
    m_Out = out;
}
void DeviceBluetooth::setState(bool state)
{
    m_State = state;
}
void DeviceBluetooth::setLinkMode(const QString& lm)
{
    m_LinkMode = lm;
}

int DeviceBluetooth::getHandle()
{
    return m_Handle;
}
const QString& DeviceBluetooth::addr() const
{
    return m_Addr;
}
const QString& DeviceBluetooth::logicalTrans() const
{
    return m_LogicalTrans;
}
bool DeviceBluetooth::getIsOut()
{
    return m_Out;
}
int DeviceBluetooth::getState()
{
    return m_State;
}
const QString& DeviceBluetooth::linkMode() const
{
    return m_LinkMode;
}
