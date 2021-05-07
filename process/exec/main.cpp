#include<unistd.h>
#include<iostream>

/*
exec系列函数
    将子进程替换成新的进程映象(当然也可以将当前进程替换掉),意味着代码段、数据段、堆栈段和PCB全部被替换
    用exec函数可以把当前进程替换为一个新进程，且新进程与原进程有相同的PID
问题
    进程名称会不会变?
*/
int main(int argc, char *argv[])
{
    int pid = fork();
    if (pid < 0) {
        std::cout << "Fork failed ...... " << std::endl;
        exit(1);
    } else if (pid == 0) {
        /*
            char *argv[] = {"ls","-l","-h",nullptr}
            execvp("ls",argv);
        */
        // execl("./a.out","./a.out",nullptr);
        execlp("ls", "ls", "-l", "-h", nullptr); //执行在环境变量中已经配置的程序
        // execlp执行成功的话是不返回的，执行失败则继续往下走
        // 也就是只要代码走到了下面这一行，就是execlp()执行失败
        perror("execlp error ......");
        exit(1);
    } else {
        sleep(1); // sleep和不sleep，终端的执行结果有些不同
        std::cout << "I am parent ...... " << "id is " << getpid() << std::endl;
    }
    return 0;
}
