#include<unistd.h>
#include<iostream>
#include <sys/wait.h>

/*

什么叫进程间通信：每个进程各自有不同的用户地址空间，任何一个进程的全局变量在另一个进程中都看不到，所以进程之间要交换数据必须通过内核，在内核中开辟一块缓冲区，进程1把数据从用户空间拷到内核缓冲区，进程2再从内核缓冲区把数据读走，内核提供的这种机制称为进程间通信

管道的使用流程:
    1. 父进程创建管道，得到两个文件描述符，一个用于读(fd[0])，一个用于写(fd[1])
    2. 父进程fork出子进程，子进程也得到了这两个文件描述符(指向同一管道)
    3. 父进程关闭管道读端，子进程关闭管道写端。父进程可以往管道里写，子进程可以从管道里读，或者相反

需要搞清楚的问题
    什么叫管道：
    管道为何不能双向通信？
    管道为什么使用环形队列机制？
    管道原理：管道实为内核使用环形队列机制，借助内核缓冲区实现的?
    可否通过管道给多个子进程写数据?

管道的使用限制：
    管道中的数据只能读取一次，一旦读走，管道中不再存在
    数据在管道中只能单向流动
    数据不能自己写，自己读
    只能在有血缘关系的进程间使用

双工和单工
    双向半双工：可以读也可以写，但是一旦指定为读端，就不能写，相反一样
    双向全双工：

管道读写行为：
    读管道：
        1. 管道有数据：read返回实际读取到的字节数
        2. 管道无数据：
            无写端：read返回 0 (类似读到文件尾)
            有写端：read阻塞等待
    写管道：
        1. 无读端：异常终止，(SIGPIPE导致的，默认终止)
        2. 有读端：
            管道已满，阻塞等待
            管道未满，返回写的字节数
*/


// 最基本的父子进程间通信
//int main(int argc, char *argv[])
//{
//    int fd[2];
//    int ret = pipe(fd);
//    if (ret == -1) {
//        return 0;
//    }

//    pid_t pid = fork();
//    if (pid > 0) {
//        close(fd[0]);
//        char ch[16] = "hello pipe";
//        write(fd[1], ch, sizeof(ch));
//        close(fd[1]);
//    } else if (pid == 0) {
//        close(fd[1]);
//        char ch[16];
//        read(fd[0], ch, sizeof(ch));
//        std::cout << " ****** " << ch << std::endl;
//    }
//    return 0;
//}

// 兄弟进程间通信
//int main(int argc, char *argv[])
//{
//    int fd[2];
//    int ret = pipe(fd);
//    if (ret == -1) {
//        return 0;
//    }

//    pid_t pid;
//    int i = 0;
//    for (i = 0; i < 2; i++) {
//        pid = fork();
//        if (pid == 0) {
//            break;
//        }
//    }

//    if (i == 2) { // parent
//        close(fd[0]);
//        close(fd[1]);
//        wait(nullptr);
//        wait(nullptr);
//    }
//    if (i == 0) { // child 1
//        close(fd[0]);
//        char ch[32] = "hello pipe in children";
//        write(fd[1], ch, sizeof(ch));
//        close(fd[1]);
//    }
//    if (i == 1) { // child 2
//        close(fd[1]);
//        char ch[32];
//        read(fd[0], ch, sizeof(ch));
//        std::cout << " ****** " << ch << std::endl;
//    }
//    return 0;
//}



// 多个写，一个读取
int main(int argc, char *argv[])
{
    int fd[2];
    int ret = pipe(fd);
    if (ret == -1) {
        return 0;
    }

    pid_t pid;
    int i = 0;
    for (i = 0; i < 2; i++) {
        pid = fork();
        if (pid == 0) {
            break;
        }
    }

    if (i == 0) { // child 1
        close(fd[0]);
        char ch[32] = "hello pipe in children 1";
        write(fd[1], ch, sizeof(ch));
        //close(fd[1]);
    } else if (i == 1) { // child 2
        close(fd[0]);
        char ch[32] = "hello pipe in children 2";
        write(fd[1], ch, sizeof(ch));
        //close(fd[1]);
    } else { // parent
        close(fd[1]);
        sleep(1);
        char ch[64];
        read(fd[0], ch, sizeof(ch));
        std::cout << " ****** " << ch << std::endl;

        wait(nullptr);
        wait(nullptr);
    }
    return 0;
}
