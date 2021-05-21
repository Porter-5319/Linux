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
    struct thrd *tval;
    tval = (thrd *)(malloc(sizeof(tval)));
    tval->var = 100;
    strcpy(tval->str, "hello thread");
    return (void *)tval;
}
// 这儿为什么不行
//void *tfn2(void *arg)
//{
//    struct thrd tval;
//    tval.var = 100;
//    strcpy(tval.str, "hello thread");
//    return (void *)&tval;
//}
// 这儿为什么行
void *tfn2(void *arg)
{
    return (void *)200;
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    int ret = pthread_create(&tid, nullptr, tfn2, nullptr);
    if (ret != 0) {
        std::cout << "Failed to create pthread ********************* " << std::endl;
        return 0;
    }
//    struct thrd *retval;
//    ret = pthread_join(tid, (void **)&retval);
//    if (ret != 0) {
//        std::cout << "Failed to pthread_join ********************* " << std::endl;
//        return 0;
//    }
//    std::cout << "val = " << retval->var << " ******* " << "str = " << retval->str << std::endl;

    int *retval;
    ret = pthread_join(tid, (void **)&retval);
    if (ret != 0) {
        std::cout << "Failed to pthread_join ********************* " << std::endl;
        return 0;
    }
    std::cout << "val = " << (void *)retval << std::endl;
}

/*
int pthread_join(pthread_t thread, void **retval);
阻塞等待线程退出,回收线程
return 0 on success , return errorno on error
retval:线程的退出状态，为什么是void**呢？因为线程退出值是void*
*/
