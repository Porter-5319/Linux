#include <iostream>
#include <signal.h>
#include <unistd.h>

void show(sigset_t *set)
{
    int i = 1;
    for (; i <= 31; i++) {
        if (sigismember(set, i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

void handle(int sig)
{
    while (true) {
        printf("xxxxxxxxxx\n");
        sleep(1);
    }
}
int main(int argc, char *argv[])
{
    struct sigaction act, oldact;
    act.sa_handler = handle;
    sigemptyset(&(act.sa_mask));
    sigaddset(&act.sa_mask, SIGTERM);
    act.sa_flags = 0; // 当sa_flags里面设置为0,sa_mask里面的信号才会屏蔽

    int ret = sigaction(SIGINT, &act, &oldact);
    if (ret == -1) {
        return 0;
    }

    for (;;) {sleep(1);}
}


//int main(int argc, char *argv[])
//{
//    // 读取当前进程的未决信号集 ***************************************************
//    // 1. 先定义信号集并清空
//    sigset_t setout;
//    sigemptyset(&setout);
//    // 2. 读取当前进程的未决信号集
//    sigpending(&setout);

//    show(&setout);
//    for (;;) {sleep(1);}
//}

//int main(int argc, char *argv[])
//{
//    // 将信号添加到阻塞信号集 ***************************************************
//    // 1. 先定义信号集并清空
//    sigset_t setin;
//    sigemptyset(&setin);
//    // 2. 将需要设置为阻塞的信号添加到信号集里面
//    sigaddset(&setin, SIGSEGV);
//    sigaddset(&setin, SIGFPE);
//    // 3. 则更改进程的信号屏蔽字
//    sigprocmask(0, &setin, nullptr);

//    // 获取当前被阻塞的信号 ***************************************************
//    // 1. 先定义信号集并清空
//    sigset_t setout;
//    sigemptyset(&setout);
//    // 2. 读取进程的当前信号屏蔽字
//    sigprocmask(0, nullptr, &setout);

//    show(&setout);

//    for (;;) {sleep(1);}
//}
