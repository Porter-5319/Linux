#include <iostream>
#include <signal.h>
#include <unistd.h>

/**
 * @brief handle : User-defined signal processing function
 * @param sig
 */
void handle(int sig)
{
    std::cout << " handle signal ******* " << sig << std::endl;
}

int main(int argc, char *argv[])
{
    // 注册自定义信号处理函数
    if (SIG_ERR == signal(SIGINT, handle)) {
        std::cout << " Failed to registered handle ******* " << SIGINT << std::endl;
        return 0;
    }

    // 将信号设置为默认处理方式
    if (SIG_ERR == signal(SIGTERM, SIG_DFL)) {
        std::cout << " Failed to registered handle ******* " << SIGTERM << std::endl;
        return 0;
    }

    for (;;) {sleep(1);}
}

