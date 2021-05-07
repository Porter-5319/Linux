#include<unistd.h>
#include<iostream>

// fork基本使用**************************************************************************************************************************
/*int main(int argc, char *argv[])
{
    std::cout << "before fork a chiled ....... " << std::endl;
    int pid = fork();
    if (pid < 0) {
        std::cout << "Fork failed ...... " << std::endl;
    } else if (pid == 0) {
        std::cout << "I am child ...... " << "parent id is " << getppid() << std::endl;
    } else {
        std::cout << "I am parent ...... " << "id is " << getpid() << std::endl;
    }
}*/
/*
pid_t fork(void);
    desc : create a child process
    return : On success, the PID of the child process is returned in the parent, and 0 is returned  in  the  child.
             On failure, -1 is returned in the parent, no child process is created, and errno is set appropriately.

getpid
getppid
getuid
getgid
*/


// for循环创建子进程，且只从主进程创建 ******************************************************************************************************
/*int main(int argc, char *argv[])
{
    std::cout << "before fork a chiled ....... " << std::endl;
    for (int i = 0; i < 5; i++) {
        int pid = fork();
        if (pid < 0) {
            std::cout << "Fork failed ...... " << std::endl;
            break;
        } else if (pid == 0) {
            std::cout << "I am child ...... " << "parent id is " << getppid() << std::endl;
            break; // 这里可以保证子线程不继续孙线程
        } else {
            std::cout << "I am parent ...... " << "id is " << getpid() << std::endl;
        }
    }
}*/

// 父子进程共享哪些内容 ******************************************************************************************************
/*
fork到底做了什么
    刚刚fork之后，父进程只从物理内存的高度复制了自己的PCB块，而代码段、数据段、堆栈、等只是复制了整个虚拟地址空间，它们的虚拟地址空间所对应的物理内存却没有复制(这个时候父子进程中变量 i 对应的虚拟地址和物理地址都相同),此时父子进程的相同数据有全局变量、.data、.text、堆、栈、环境变量、用户id、宿主目录、进程工作目录、信号处理方式,不同数据有进程ID、fork返回值、父进程ID、进程运行时间、闹钟、未决信号集。等到虚拟地址空间被写时，对应的物理内存空间被复制（这个时候父子进程中变量 i 对应的虚拟地址还是相同的，但是物理地址不同）

fork后父子进程一般哪些数据共享，哪些不共享
    在数据类型为全局变量时，父子进程之间的数据不共享
    当数据类型为局部变量的时候，父子进程之间的数据不共享
    当数据类型是动态开辟时，父子进程的数据不共
    上面这些读时共享写时复制
    父子进程之间共享文件描述符，具体而言是共享了文件偏移量
    父子进程之间共享mmap建立的映射区
未解决的问题
    向栈里面写数据，堆和数据区是否也会复制
    fork和vfork的关系
    两个进程打开同一个文件会怎样
    父子进程是否共享代码段
    父进程是否共享数据库连接
*/

int main(int argc, char *argv[])
{
    int g = 100;
    int pid = fork();
    if (pid < 0) {
        std::cout << "Fork failed ...... " << std::endl;
    } else if (pid == 0) {
        g = 500;
        std::cout << "child ...... " << &g << " ************* " << g << std::endl;
    } else {
        std::cout << "parent ...... " << &g << " ************* " << g << std::endl;
    }
}
