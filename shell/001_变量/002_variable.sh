#!/bin/bash
# 变量的赋值
## 等好前后不能有空格，如果有空格会怎么样
### var =12 var: 未找到命令
#### 尝试运行一个var的命令，带着一个"=12" 的参数
### var= 12 12：未找到命令
#### 尝试运行一个 "12" 的命令 并带着一个被赋值为""环境变量var
##变量的赋值方式
###直接赋值
var=100
echo "The value of \"var\" is $var."
###使用let赋值
let var=${var}+100
echo "The value of \"var\" is $var."
###在for循环中赋值
for a in 100 200 300 400 500 600
do
	let var=${var}+${a}
	echo "The value of \"var in for \" is $var , a = ${a}."
done
###使用read命令赋值
echo -n "Enter value :"
read var
echo "The value of \"var in read \" is $var."
###使用命令替换赋值
var=`ls -l`
echo "The value of \"var in 命令替换 \" is $var."
echo "The value of \"var in 命令替换 \" is "$var"." # 注意和上面的不同
var=$(ls)
echo "The value of \"var in 命令替换 \" is $var."
echo "The value of \"var in 命令替换 \" is "$var"." # 注意和上面的不同

# 变量的引用 
## 第一个没有引用
var=100
echo var
echo $var
echo ${var}
echo "$var"
echo "${var}"

echo "****************************"
#变量引用和变量替换
## 引用一个变量保留其中的空白
## 替换一个变量不保留其中的空白
var="A B  C   D"
echo $var # 变量替换
echo ${var} # 变量替换
echo "$var" # 变量引用
echo "${var}" # 变量引用

#全引用-将$解释为单独的字符，而不是变量前缀
echo '$var'

#变量设为null和unset变量的区别
var=
echo "\$var = $var"
unset var
echo "\$var = $var"

#变量类型替换
var1=1234
echo "var1 = $var1"
let var1+=1 # += 前后不能有空格
echo "var1 = $var1"
let "var1 += 1" # += 前后可以有空格 
echo "var1 = $var1"
## 整型 -> 字符串
var2=${var1/12/CC} # 将var1中的 12 替换成 CC
echo "var2 = $var2"
## 字符串 -> 整型
var3=${var2/CC/12}
echo "var3 = $var3"
## let 转换
let "var2 += 1" # 给整型 += 1 操作，会直接变成1
echo "var2 = $var2"
## null变量和未声明的变量
var4=
let "var4 += 1" # null变量会变成整型
echo "var4 = $var4"
let "var5 += 1" # 未声明变量将转换成一个整型变量
echo "var5 = $var5"
