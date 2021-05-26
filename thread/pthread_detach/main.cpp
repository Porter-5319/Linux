#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

void *tfn(void *arg)
{
    std::cout << "I am in tfn >>>>>>>>>>>>> " << std::endl;
    return nullptr;
}

void *tfnWhile(void *arg)
{
    while (true) {
        std::cout << "I am in tfnWhile >>>>>>>>>>>>> " << std::endl;
        sleep(1);
    }
    return nullptr;
}

//int main(int argc, char *argv[])
//{
//    pthread_t tid;
//    int ret = pthread_create(&tid, nullptr, tfn, nullptr);
//    if (ret != 0) {
//        std::cout << "Failed to create pthread ********************* " << std::endl;
//        return 0;
//    }

//    ret = pthread_detach(tid);
//    if (ret != 0) {
//        std::cout << "Failed to pthread_detach ********************* " << std::endl;
//    }

//    sleep(1);

//    // 此时pthread_join会返回非0，因为线程已经分离，线程会自己进行回收
//    ret = pthread_join(tid, nullptr);
//    if (ret != 0) {
//        std::cout << "Failed to pthread_join ********************* " << std::endl;
//    }

//    return 0;
//}

//int main(int argc, char *argv[])
//{
//    pthread_t tid;
//    int ret = pthread_create(&tid, nullptr, tfnWhile, nullptr);
//    if (ret != 0) {
//        std::cout << "Failed to create pthread ********************* " << std::endl;
//        return 0;
//    }

//    ret = pthread_detach(tid);
//    if (ret != 0) {
//        std::cout << "Failed to pthread_detach ********************* " << std::endl;
//    }

//    sleep(5);
//    std::cout << "main thread exit ********************* " << std::endl;
//    return 0;
//}

int main(int argc, char *argv[])
{
    pthread_t tid;
    int ret = pthread_create(&tid, nullptr, tfnWhile, nullptr);
    if (ret != 0) {
        std::cout << "Failed to create pthread ********************* " << std::endl;
        return 0;
    }
    ret = pthread_join(tid, nullptr);
    if (ret != 0) {
        std::cout << "Failed to pthread_join ********************* " << std::endl;
    }
    sleep(5);
    std::cout << "main thread exit ********************* " << std::endl;
    return 0;
}

/*
    int pthread_join(pthread_t thread, void **retval);
*/
