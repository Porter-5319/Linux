#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
struct thrd {
    int var;
    char str[256];
};
void *tfn(void *arg)
{
    while (true) {
        std::cout << "I am in tfn >>>>>>>>>>>>> " << std::endl;
        sleep(1);
    }
    return nullptr;
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    int ret = pthread_create(&tid, nullptr, tfn, nullptr);
    if (ret != 0) {
        std::cout << "Failed to create pthread ********************* " << std::endl;
        return 0;
    }


    sleep(5);
    ret = pthread_cancel(tid);
    if (ret != 0) {
        std::cout << "Failed to pthread_join ********************* " << std::endl;
        return 0;
    }

}

/*
int pthread_join(pthread_t thread, void **retval);
*/
