#!/bin/bash

# 变量替换的方式有两种
## var=`command`
## var=$(command)

## 命令替换的简单使用
begin_time=`date +%s`
sleep 1
end_time=`date +%s`
run_time=$((end_time-begin_time))
echo "run_time: $run_time"


## 命令替换结果使用 "" 和不使用的区别
### 使用 "" ：如果var中有换行或者连续空格，则会正常显示
### 不使用 "" ：如果var中有换行或者连续空格，则会会将换行变成一个空格，将连续空格变成一个空格
var=`ls -l`
echo $var
echo "--------------------------------------"
echo "$var"


## 如何选择这两种方法
### 一般情况下两种方式是等价的
### 但是$()支持嵌套，但是反引号不支持
### $()仅在Bash Shell中有效，但是``在多个shell中有效

