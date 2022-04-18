#include "BTTool.h"

#include "DeviceBluetooth.h"

/* Unofficial value, might still change */
#define LE_LINK		0x03

BTTool::BTTool()
{

}

int BTTool::getConnectedBt(QList<DeviceBluetooth*>& lstBlue)
{
    int dev_id = hci_get_route(nullptr);
    int sock = hci_open_dev( dev_id );

    struct hci_conn_list_req *cl = nullptr;
    struct hci_conn_info *ci = nullptr;
    cl = static_cast<hci_conn_list_req*>(malloc(10 * sizeof(*ci) + sizeof(*cl)));
    if(nullptr == cl){
        qInfo() << "Error : hci_conn_list_req malloc";
        hci_close_dev(sock);
        return -1;
    }

    cl->dev_id = dev_id;
    cl->conn_num = 10;
    ci = cl->conn_info;

    if (ioctl(sock, HCIGETCONNLIST, (void *) cl)) {
        qInfo() << "Error : ioctl HCIGETCONNLIST";
        hci_close_dev(sock);
        return -1;
    }

    for (int i = 0; i < cl->conn_num; i++, ci++){
        DeviceBluetooth* blue = new DeviceBluetooth();

        // 获取物理地址
        char addr[18];
        ba2str(&ci->bdaddr, addr);
        blue->setAddr(addr);

        // 获取链接模式linkMode
        char* lm = hci_lmtostr(ci->link_mode);
        blue->setLinkMode(lm);

        // 获取逻辑传输类型
        blue->setLogicalTrans(type2str(ci->type));

        blue->setIsOut(ci->out);
        blue->setState(ci->state);
        blue->setHandle(ci->handle);

        lstBlue.append(blue);
    }

    hci_close_dev(sock);
    return cl->conn_num;
}

QString BTTool::getConnectBtName(const QString& addr)
{
    int dev_id = hci_get_route(nullptr);
    if(dev_id < 0)
        return "";

    int sock = hci_open_dev( dev_id );
    if(sock < 0)
        return "";

    bdaddr_t bdaddr;
    str2ba(addr.toStdString().c_str(),&bdaddr);

    char name[64];
    if (hci_read_remote_name(sock, &bdaddr, sizeof(name), name, 25000) != 0){
        hci_close_dev(sock);
        return "";
    }
    return QString(name);
}

QString BTTool::getConnectBtClkoff(const QString& addr)
{
    int dev_id = hci_get_route(nullptr);
    if(dev_id < 0)
        return "";

    int sock = hci_open_dev( dev_id );
    if(sock < 0)
        return "";

    bdaddr_t bdaddr;
    str2ba(addr.toStdString().c_str(),&bdaddr);

    struct hci_conn_info_req *cr = static_cast<hci_conn_info_req*>(malloc(sizeof(*cr) + sizeof(struct hci_conn_info))) ;
    if (!cr) {
        return "";
    }

    bacpy(&cr->bdaddr, &bdaddr);
    cr->type = ACL_LINK;

    if (ioctl(sock, HCIGETCONNINFO, (unsigned long) cr) < 0) {
        return "";
    }

    uint16_t offset;
    if (hci_read_clock_offset(sock, htobs(cr->conn_info->handle), &offset, 1000) < 0) {
        return "";
    }

    char info[24];
    sprintf(info,"Clock offset: 0x%4.4x",btohs(offset));

    free(cr);
    hci_close_dev(sock);
    return QString(info);
}

QString BTTool::type2str(unsigned short type)
{
    switch (type) {
    case SCO_LINK:
        return "SCO";
    case ACL_LINK:
        return "ACL";
    case ESCO_LINK:
        return "eSCO";
    case LE_LINK:
        return "LE";
    default:
        return "Unknown";
    }
}

