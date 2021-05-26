#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

//void *tfn(void *arg)
//{
//    while (true) {
//        std::cout << "hello ";
//        sleep(rand() % 3);
//        std::cout << "world" << std::endl;
//    }
//    return nullptr;
//}

//int main(int argc, char *argv[])
//{
//    pthread_t tid;
//    int ret = pthread_create(&tid, nullptr, tfn, nullptr);
//    if (ret != 0) {
//        std::cout << "Failed to create pthread ********************* " << std::endl;
//        return 0;
//    }
//    while (true) {
//        std::cout << "HELLO ";
//        sleep(rand() % 3);
//        std::cout << "WORLD" << std::endl;
//    }

//    ret = pthread_join(tid, nullptr);
//    if (ret != 0) {
//        std::cout << "Failed to pthread_join *********************" << std::endl;
//    }

//    std::cout << "main thread exit ********************* " << std::endl;
//    return 0;
//}

// 要么一直执行子线程，要么一直执行主线程
// 原因是while循环
//pthread_mutex_t mutex;
//void *tfn(void *arg)
//{
//    while (true) {
//        pthread_mutex_lock(&mutex);
//        std::cout << "hello ";
//        sleep(rand() % 3);
//        std::cout << "world" << std::endl;
//        pthread_mutex_unlock(&mutex);
//    }
//    return nullptr;
//}

//int main(int argc, char *argv[])
//{
//    pthread_t tid;
//    int ret = pthread_mutex_init(&mutex, nullptr);
//    if (ret != 0) {
//        std::cout << "Failed to pthread_mutex_init ********************* " << std::endl;
//    }

//    ret = pthread_create(&tid, nullptr, tfn, nullptr);
//    if (ret != 0) {
//        std::cout << "Failed to create pthread ********************* " << std::endl;
//        return 0;
//    }
//    while (true) {
//        pthread_mutex_lock(&mutex);
//        std::cout << "HELLO ";
//        sleep(rand() % 3);
//        std::cout << "WORLD" << std::endl;
//        pthread_mutex_unlock(&mutex);
//    }

//    ret = pthread_join(tid, nullptr);
//    if (ret != 0) {
//        std::cout << "Failed to pthread_join *********************" << std::endl;
//    }

//    std::cout << "main thread exit ********************* " << std::endl;
//    return 0;
//}


pthread_mutex_t mutex;
void *tfn(void *arg)
{
    while (true) {
        pthread_mutex_lock(&mutex);
        std::cout << "hello ";
        sleep(rand() % 3);
        std::cout << "world" << std::endl;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return nullptr;
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    int ret = pthread_mutex_init(&mutex, nullptr);
    if (ret != 0) {
        std::cout << "Failed to pthread_mutex_init ********************* " << std::endl;
    }

    ret = pthread_create(&tid, nullptr, tfn, nullptr);
    if (ret != 0) {
        std::cout << "Failed to create pthread ********************* " << std::endl;
        return 0;
    }
    while (true) {
        pthread_mutex_lock(&mutex);
        std::cout << "HELLO ";
        sleep(rand() % 3);
        std::cout << "WORLD" << std::endl;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }

    ret = pthread_join(tid, nullptr);
    if (ret != 0) {
        std::cout << "Failed to pthread_join *********************" << std::endl;
    }

    std::cout << "main thread exit ********************* " << std::endl;
    return 0;
}
