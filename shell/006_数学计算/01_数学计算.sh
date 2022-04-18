#!/bin/bash

## (())
echo $((1+2))
i=5
((i+=10))
echo $i
((i=i*2))
echo $i

((a=1+2**3-4%3))
echo $a
echo $((3<8))

## let
let i=121
echo $i
let i+=21
echo $i
let i+=1 i+=2
echo $i

## []
n=5
m=6 # 下面两种用法没有太大区别
echo $[n*m]
echo $[$n*$m]
echo $[(10+20)*3]
echo $[3*(n+m)]


## expr
expr 2 + 3 # 必须空格
expr 4 \* 5 # * 必须转义
expr \( 2 + 3 \) \* 2 # 括号和*必须转义
n=`expr $m + 10` # 变量必须使用$
echo $n

## bc可进行浮点运算
echo "3*8"|bc
ret=$(echo "10/3"|bc)
echo $ret
ret=$(echo "scale=4;10/3"|bc) # 指定精度
echo $ret
x=10
echo "scale=5;index=$x+2;e(index)"|bc -l
m=31
n=$(echo "obase=16;$m"|bc)
echo $n

## 当不使用上面各种方式，直接通过运算符计算时使用declare -i
declare -i mi ni ret
mi=10
ni=32
ret=$mi+$ni
echo $ret


