#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

void *tfn(void *arg)
{
    std::cout << "I am in tfn >>>>>>>>>>>>> " << std::endl;
    return nullptr;
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    pthread_attr_t attri;
    int ret = pthread_attr_init(&attri);
    if (ret != 0) {
        std::cout << "Failed to pthread_attr_init *********************" << std::endl;
    }

    ret = pthread_attr_setdetachstate(&attri, PTHREAD_CREATE_DETACHED);
    if (ret != 0) {
        std::cout << "Failed to pthread_attr_setdetachstate ********************* " << std::endl;
        return 0;
    }

    ret = pthread_create(&tid, &attri, tfn, nullptr);
    if (ret != 0) {
        std::cout << "Failed to create pthread ********************* " << std::endl;
        return 0;
    }

    ret = pthread_attr_destroy(&attri);
    if (ret != 0) {
        std::cout << "Failed to pthread_attr_destroy *********************" << std::endl;
    }

    ret = pthread_join(tid, nullptr);
    if (ret != 0) {
        std::cout << "Failed to pthread_join *********************" << std::endl;
    }

    std::cout << "main thread exit ********************* " << std::endl;
    return 0;
}


/*
 *  pthread_attr_t
 *      设置线程分离
 *      获取线程栈和设置线程栈大小
 *
 * 主线程退出，其它线程不退出，可以在主线程调用pthread_exit();
 * 如何避免僵尸线程
        pthread_join
        pthread_detach
        pthread_attr_t
        被join的线程可能会在join函数返回前释放自己的所有内存资源，所以不应当返回被回收线程栈中的值
malloc和mmap申请的内存可以被其它线程释放
应该避免多线程中调用fork，除非马上exec，子进程中只有调用fork的线程存在，其它线程在子进程中均pthread_exit
信号的复杂语义很难和多线程共存，应避免在多线程引入信号机制,各个线程有独立的信号屏蔽字，但是有共同的未决信号
*/
