#include<unistd.h>
#include<iostream>
#include <sys/wait.h>

/*
什么是孤儿进程：一个父进程退出，而它的一个或多个子进程还在运行，那么那些子进程将成为孤儿进程。孤儿进程将被init进程(进程号为1)所收养，并由init进程对它们完成状态收集工作
什么是僵尸进程：子进程先于父进程退出后，子进程的PCB需要其父进程释放(回收)，但是父进程并没有释放子进程的PCB(没有去wait/waitpid)，这样的子进程就称为僵尸进程，僵尸进程实际上是一个已经死掉的进程
孤儿进程和僵尸进程产生的原因：
    归根结底还是Unix操作系统提供了一种这样的机制：让父进程可以知道子进程结束时的状态信息
    如果父进程一直比较忙，或者因为其他原因没有去wait/waitpid子进程结束时候留下的状态信息，那这些已经结束的线程遗留的数据结构就无从清理，也就产生了所谓的僵尸进程，因为数据结构里包含pid等信息，操作系统的pid是有限的，因此僵尸进程是有害的。
    如果父进程先于子进程结束，那子进程无父进程了，如果之后子进程也结束，谁去释放他遗留下来的数据结构呢？这个无父进程的子进程就叫孤儿进程，他将会被init进程（pid=1）托管，之后此子进程结束的话，他的遗留数据结构将会被init进程去wait/waitpid释放
    孤儿进程与僵尸进程不同的是，由于父进程已经死亡，系统会帮助父进程回收处理孤儿进程。所以孤儿进程实际上是不占用资源的，因为它终究是被系统回收了。不会像僵尸进程那样占用ID,损害运行系统。

wait函数的三个作用：
    1）阻塞等待子进程退出 : 主进程调用wait函数会阻塞等待子进程结束。
    2）回收子进程残留资源 : 等待子进程结束后会回收子进程资源，但是是无差别回收。比如说一个进程有5个子进程，wait函数只会等待一个(任意一个)，回收完之后就继续往下走，不等待其它的进程。
    3）获取子进程结束状态(退出原因) : 子进程退出的方式主要有两种(实际不止)，正常退出和异常退出(信号)
        如何判断正常退出：使用 WIFEXITED(status) 判断是否正常退出，如果返回true 则使用 WEXITSTATUS(status) 获取正常退出的返回值
        如何判断异常退出：使用 WIFSIGNALED(status) 判断是否是信号导致的退出，如果返回true 则使用 WTERMSIG(status)
*/

// wait函数的使用 ***************************************************************************************************
/*int main(int argc, char *argv[])
{
    int pid = fork();
    if (pid < 0) {
        std::cout << "Fork failed ...... " << std::endl;
        exit(1);
    } else if (pid == 0) {
        std::cout << "I am child ...... " << "id is " << getpid() << std::endl;
        sleep(5);
        std::cout << "I am child ...... " << "finshed" << std::endl;
    } else {
        std::cout << "I am parent ...... " << "id is " << getpid() << std::endl;
        int status;
        // int wpid = wait(nullptr); 不关心子进程退出原因
        int wpid = wait(&status);
        // 正常退出组合 : 使用 WIFEXITED(status) 判断是否正常退出，如果返回true 则使用 WEXITSTATUS(status) 获取正常退出的返回值
        if (WIFEXITED(status)) {
            std::cout << "return value is ........... " << WEXITSTATUS(status) << std::endl;
        }
        // 信号中断组合 : 使用 WIFSIGNALED(status) 判断是否是信号导致的退出，如果返回true 则使用 WTERMSIG(status)
        if (WIFSIGNALED(status)) {
            std::cout << "return value is ........... " << WTERMSIG(status) << std::endl;
        }
        std::cout << wpid << " ......  finshed " << std::endl;
    }
    return 0;
}*/


/*int main(int argc, char *argv[])
{
    int wpid = -1, pid = -1;
    for (int i = 0; i < 5; i++) {
        pid = fork();
        if (pid > 0) { // parent
            if (i == 2) {
                wpid = pid;
                std::cout << "wait pid 001 ***************** " << wpid << std::endl;
            }
            continue;
        } else {
            break;
        }
    }

    int status;
    if (pid != 0) {
        int id = waitpid(wpid, &status, WUNTRACED);
        std::cout << "wait pid 002 ***************** " << id << std::endl;
    } else
        std::cout << "I am child ************* " << getpid() << std::endl;
    return 0;
}*/


/*int main(int argc, char *argv[])
{
    int i = 0;
    for (; i < 5; i++) {
        int pid = fork();
        if (pid > 0) { // parent
            continue;
        } else {
            std::cout << "pid = " << getpid() << std::endl;
            sleep(1);
            break;
        }
    }

    if (i == 5) {
        int wpid = waitpid(-1, nullptr, WUNTRACED);
        while (wpid != -1) {
            std::cout << "wpid = " << wpid << std::endl;
            wpid = waitpid(-1, nullptr, WUNTRACED);
        }
    }
    return 0;
}*/

// waitpid等待多个子进程退出 *********************************************************
int main(int argc, char *argv[])
{
    int i = 0;
    for (; i < 5; i++) {
        int pid = fork();
        if (pid > 0) { // parent
            continue;
        } else {
            std::cout << "pid = " << getpid() << std::endl;
            sleep(1);
            break;
        }
    }

    if (i == 5) {
        int wpid = waitpid(-1, nullptr, WNOHANG);
        while (wpid != -1) {
            if (wpid == 0)
                sleep(1);
            else
                std::cout << "wpid = " << wpid << std::endl;

            wpid = waitpid(-1, nullptr, WNOHANG);
        }
    }
    return 0;
}
