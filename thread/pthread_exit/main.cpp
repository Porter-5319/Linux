#include <pthread.h>
#include <iostream>
#include <unistd.h>

void *tfn0(void *arg)
{
    long i = long(arg);
    sleep(i);
    pthread_t tid = pthread_self(); // 获取线程id
    std::cout << "tfn : pid = " << getpid() << " **** " << "tid = " << tid << "      i = " << i << std::endl;
    return nullptr;
}

void *tfn1(void *arg)
{
    long i = long(arg);
    sleep(i);
    pthread_t tid = pthread_self(); // 获取线程id
    if (i == 2) {
        exit(0); // 此时整个进程都会退出
    }
    std::cout << "tfn : pid = " << getpid() << " **** " << "tid = " << tid << "      i = " << i << std::endl;
    return nullptr;
}
void *tfn2(void *arg)
{
    long i = long(arg);
    sleep(i);
    pthread_t tid = pthread_self(); // 获取线程id
    if (i == 2) {
        return nullptr;  // 此时仅仅这个线程退出
    }
    std::cout << "tfn : pid = " << getpid() << " **** " << "tid = " << tid << "      i = " << i << std::endl;
    return nullptr;
}


void ret1(void)
{
    return;
}
void ret2(void)
{
    pthread_exit(nullptr); // 退出当前线程
}
void *tfn3(void *arg)
{
    long i = long(arg);
    sleep(i);
    pthread_t tid = pthread_self(); // 获取线程id
    if (i == 2) {
        ret1();   // 不会退出线程
    }
    std::cout << "tfn : pid = " << getpid() << " **** " << "tid = " << tid << "      i = " << i << std::endl;
    return nullptr;
}

void *tfn4(void *arg)
{
    long i = long(arg);
    sleep(i);
    pthread_t tid = pthread_self(); // 获取线程id
    if (i == 2) {
        ret2();   // 退出当前线程
    }
    std::cout << "tfn : pid = " << getpid() << " **** " << "tid = " << tid << "      i = " << i << std::endl;
    return nullptr;
}


int main(int argc, char *argv[])
{
    pthread_t tid;
    int ret ;
    for (int i = 1; i <= 5; i++) {
        ret = pthread_create(&tid, nullptr, tfn0, (void *)(i));
        if (ret != 0) {
            std::cout << "error" << std::endl;
        }
    }

    pthread_exit(nullptr); // 主线程退出了，那么进程如何退出呢？
    return 0;

    sleep(6); // sleep  让线程执行结束
}

// void pthread_exit(void *retval);
