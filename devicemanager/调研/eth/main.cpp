#include <QCoreApplication>
#include <QDebug>

#include <sys/socket.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <linux/sockios.h>

#include "ethtool-copy.h"

static char *unparse_wolopts(int wolopts)
{
    static char buf[16];
    char *p = buf;

    memset(buf, 0, sizeof(buf));

    if (wolopts) {
        if (wolopts & WAKE_PHY)
            *p++ = 'p';
        if (wolopts & WAKE_UCAST)
            *p++ = 'u';
        if (wolopts & WAKE_MCAST)
            *p++ = 'm';
        if (wolopts & WAKE_BCAST)
            *p++ = 'b';
        if (wolopts & WAKE_ARP)
            *p++ = 'a';
        if (wolopts & WAKE_MAGIC)
            *p++ = 'g';
        if (wolopts & WAKE_MAGICSECURE)
            *p++ = 's';
    } else {
        *p = 'd';
    }

    return buf;
}

static int parse_wolopts(char *optstr, __uint32_t *data)
{
    *data = 0;
    while (*optstr) {
        switch (*optstr) {
            case 'p':
                *data |= WAKE_PHY;
                break;
            case 'u':
                *data |= WAKE_UCAST;
                break;
            case 'm':
                *data |= WAKE_MCAST;
                break;
            case 'b':
                *data |= WAKE_BCAST;
                break;
            case 'a':
                *data |= WAKE_ARP;
                break;
            case 'g':
                *data |= WAKE_MAGIC;
                break;
            case 's':
                *data |= WAKE_MAGICSECURE;
                break;
            case 'd':
                *data = 0;
                break;
            default:
                return -1;
        }
        optstr++;
    }
    return 0;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd < 0){
        qInfo() << "创建 socket 失败 ***** " << fd;
        exit(0);
    }

    struct ifreq ifr;
    memset(&ifr,0,sizeof (ifr));
    strcpy(ifr.ifr_name,"eno1");

    struct ethtool_wolinfo wolinfo;
    wolinfo.cmd = ETHTOOL_GWOL;
    ifr.ifr_data = reinterpret_cast<char*>(&wolinfo);

    if(0 == ioctl(fd, SIOCETHTOOL, &ifr)){
        qInfo() << "Supports Wake-on: " << unparse_wolopts(wolinfo.supported) << " *** " << wolinfo.supported;
        qInfo() << "Wake-on: " << unparse_wolopts(wolinfo.wolopts) << " *** " << wolinfo.wolopts;
        // wolinfo.supported = 47 则说明该网卡支持
        // wolinfo.wolopts = 32 该功能开启了
        // wolinfo.wolopts = 0  该功能关闭了
    }



    // 设置是否支持
    struct ethtool_wolinfo wol;
//    wol.wolopts = 0;  // d 关闭网络唤醒
    wol.wolopts = 0 | WAKE_MAGIC; // g 打开网络唤醒
    wol.cmd = ETHTOOL_SWOL;

    memset(&ifr,0,sizeof (ifr));
    strcpy(ifr.ifr_name,"eno1");
    ifr.ifr_data = reinterpret_cast<char*>(&wol);
    if(0 == ioctl(fd, SIOCETHTOOL, &ifr)){
        qInfo() << "设置成功";
    }else{
        qInfo() << "设置失败";
    }


    return a.exec();
}
