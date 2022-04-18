#!/bin/bash
## 确定是否是内建命令
### type cmd
type cd

## 内建命令会比外部命令执行得更快，执行外部命令时不但会触发磁盘 I/O，还需要 fork 出一个单独的进程来执行，执行完成后再退出。而执行内建命令相当于调用当前 Shell 进程的一个函数



## alias 创建一个别名
### 语法：alias new_name='command' 单引号
#### 在代码中使用 alias 命令定义的别名只能在当前 Shell 进程中使用，在子进程和其它进程中都不能使用。当前 Shell 进程结束后，别名也随之消失
#alias dd='date +%s'
#begin=$(dd)  
#finish=$(dd)
#difference=$((finish - begin))
#echo "run time: ${difference}s"
## unalias 删除别名
### unalias name 删除指定别名
### unalias -a 删除所有别名



## echo 命令
### 不换行 -n
echo -n "hello "
echo "shell"
### 解析转义 -e 默认情况下，echo 不会解析以反斜杠\开头的转义字符
echo "hello \nworld"
echo -e "hello \nworld"
### \c + -e = -n 
#### \c 不换行转义
#### -e 解析转义



## read命令
### 两次输入密码是否相同
if
    read -t 20 -sp "Enter password in 20 seconds(once) > " pass1 && printf "\n" &&  #第一次输入密码
    read -t 20 -sp "Enter password in 20 seconds(again)> " pass2 && printf "\n" &&  #第二次输入密码
    [ $pass1 == $pass2 ]  #判断两次输入的密码是否相等
then
    echo "Valid password"
else
    echo "Invalid password"
fi
#### 上面的if有多个语句，结果以最后一个的返回为准


# declare 设置变量属性
### 将变量声明为整数
declare -i m n ret  #将多个变量声明为整数
m=10
n=30
ret=$m+$n
echo $ret
