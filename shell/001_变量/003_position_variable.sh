#!/bin/bash
echo "******************** 位置变量 *********************"
# $0 是脚本文件名称
# $1 是第一个参数
echo "\$0 = $0"
echo "\$1 = $1"
echo "\"`basename $0`\"" # 打印的名称不带路径
if [ -n "$1" ] # 判断$1是否被赋值，也就是运行脚本的时候有没有带参数
then
	echo "Parameter #1 is $1"
fi

if [ -n "${10}" ] # 当大于9时必须使用{}，否则是$1 0
then
	echo "Parameter #1 is $1"
fi

# $* 所有参数
echo $*

# $# 参数的个数，不算$0
echo $#
MINPARAMS=10
if [ $# -lt "$MINPARAMS" ]
then
	echo "This script needs at least $MINPARAMS command-line arguments !"
fi

# 获取最后一个参数
## 方法一
echo ${!#}
## 方法二
args=$#
echo ${!args}

# 如何处理需要参数但是没有传入参数的情况
## 方法一
var_=$1_
echo "var_ = $var_"
var1=${var_/_/}
echo "var1 = $var1"
## 方法二
if [ -z $1 ]
then
	echo "There is no \$1"
fi
## 方法三参数替换
DEFAULT_VALUE=hhh
echo ${1:=word}
echo "var2 = $var2"


