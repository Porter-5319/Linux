#include <iostream>
#include <signal.h>
#include <unistd.h>


// 三参数信号处理函数的实现 **********************************
void handle(int signum, siginfo_t *info, void *myact) //三参数信号处理函数的实现
{
    std::cout << "signum ************* " << signum << std::endl;
    std::cout << "info **************** " << (char *)((*info).si_ptr) << std::endl;
}

int main(int argc, char *argv[])
{
    struct sigaction act, oldact;
    act.sa_sigaction = handle; //三参数信号处理函数
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGTERM, &act, &oldact);

    pid_t pid = getpid();
    union sigval mysigval;
    char ch[] = "Info from handle";
    mysigval.sival_ptr = ch;

    for (;;) {
        sigqueue(pid, SIGTERM, mysigval); //向本进程发送信号，并传递附加信息
        sleep(2);
    }
}


// sa_mask的使用 *************************************************************
/*
void handleINT(int sig)
{
    for (int i = 0; i < 20; i++) {
        std::cout << " handleINT ******* " << sig << std::endl;
        sleep(1);
    }
}

void handleTERM(int sig)
{
    for (int i = 0; i < 5; i++) {
        std::cout << " handleTERM ******* " << sig << std::endl;
        sleep(1);
    }
}

int main(int argc, char *argv[])
{
    struct sigaction act, oldact;
    act.sa_handler = handleINT;
    sigaddset(&act.sa_mask, SIGTERM); // 用来设置在处理该信号时暂时将sa_mask 指定的信号搁置
    sigaction(SIGINT, &act, &oldact);

    // registered SIGTERM
    signal(SIGTERM, handleTERM);

    for (;;) {sleep(1);}
}*/
