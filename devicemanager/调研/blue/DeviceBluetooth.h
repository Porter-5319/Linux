#ifndef DEVICEBLUETOOTH_H
#define DEVICEBLUETOOTH_H

#include <QObject>

class DeviceBluetooth : public QObject
{
    Q_OBJECT
public:
    explicit DeviceBluetooth(QObject *parent = nullptr);

    void setHandle(int handle);
    void setAddr(const QString& addr);
    void setLogicalTrans(const QString& logicalTrans);
    void setIsOut(bool out);
    void setState(bool state);
    void setLinkMode(const QString& lm);

    int getHandle();
    const QString& addr() const;
    const QString& logicalTrans() const;
    bool getIsOut();
    int getState();
    const QString& linkMode() const;

private:
    // 一下6个变量来源于hci.h中的hci_conn_info结构体
    /*
        struct hci_conn_info {
            uint16_t handle;
            bdaddr_t bdaddr;
            uint8_t  type;
            uint8_t	 out;
            uint16_t state;
            uint32_t link_mode;
        };
    */
    int          m_Handle;            //<! 句柄，暂时没有用处
    QString      m_Addr;              //<! 蓝牙设备的物理地址
    QString      m_LogicalTrans;      //<! 逻辑传输类型 ACL SCO LE
    bool         m_Out;               //<! 目前没有搞明白什么意思
    int          m_State;             //<! 目前没有搞明白什么意思
    QString      m_LinkMode;          //<! 主从结构
};

#endif // DEVICEBLUETOOTH_H
