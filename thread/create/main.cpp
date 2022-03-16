#include <pthread.h>
#include <iostream>
#include <unistd.h>

//void *tfn(void *arg)
//{
//    pthread_t tid;
//    tid = pthread_self(); // 获取线程id
//    std::cout << "tfn : pid = " << getpid() << " **** " << "tid = " << tid  << std::endl;
//    return nullptr;
//}

//int main(int argc, char *argv[])
//{
//    pthread_t tid;
//    int ret = pthread_create(&tid, nullptr, tfn, nullptr);
//    sleep(1); // sleep 1秒 让线程执行结束
//}

//    long i = (long)arg;
//std::cout << " **************** " << &i << "   " << &i << std::endl;


void *tfn(void *arg)
{
    int i = *((int *)(arg));
    sleep(i);
    pthread_t tid = pthread_self(); // 获取线程id
    std::cout << "tfn : pid = " << getpid() << " **** " << "tid = " << tid << "      i = " << i << std::endl;
    return nullptr;
}
int main(int argc, char *argv[])
{
    pthread_t tid;
    int ret ;
    for (int i = 1; i <= 5; i++) {
        int index = i;
        std::cout << " **************** " << &index << std::endl;
        ret = pthread_create(&tid, nullptr, tfn, (void *)(&index));
        if (ret != 0) {
            std::cout << "error" << std::endl;
        }
    }
    sleep(6); // sleep  让线程执行结束
}
/*
tfn : pid = 6811 **** tid = 139824888919808      i = 2
tfn : pid = 6811 **** tid = 139824880527104      i = 3
tfn : pid = 6811 **** tid = 139824872134400      i = 5
tfn : pid = tfn : pid = 6811 **** tid = 139824855348992      i = 5
6811 **** tid = 139824863741696      i = 5
*/
