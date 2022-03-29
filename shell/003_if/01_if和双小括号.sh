#!/bin/bash

# (()) 的使用，主要用来整数运算，一般符合C语言语法的都可以
## 简单的整数运算
echo $((1+1)) # 通过$获取运算的结果，注意这里不是执行的退出状态
echo $((1*9+8)) # 结果是17
### 注意这里不能丢掉$，因为仅仅双括号返回的是退出状态
echo $((100*(100+1)/2))

## (()) 用来重新计算变量，注意要符合C语法
var=10
((var*=10)) # 这里使用 var*=10  或 var=$var*10 都不行
((var++))
echo $var

## (()) 进行逻辑运算
echo $((3<8))
echo $((8==8))
echo $((8>7&&5==5))

## 利用 (( )) 同时对多个表达式进行计算
((var1=5+78,var2=6+89)) #先计算第一个表达式，再计算第二个表达式
echo $var1
echo $var2
var3=$((5+78,6+89)) # 以最后一个表达式的结果作为(())命令的执行结果
echo $var3




# if与(())的结合使用
## if判断的是返回状态不是执行结果
## 返回的状态是0表示成功
if ((1+1)) # 注意这里使用 $((1+1)) 会报错
then
	echo "返回状态是：$?，执行的结果是$((1+1))"
fi

## 注意下面两段的不同
### if ((var4==100)) 和 if (($var4==100))
#### 从目前来看没有区别
var4=100
if ((var4==100))
then
	echo "返回状态是：$?，执行的结果是$((var4==100))"
fi
	
if (($var4==100))
then
	echo "返回状态是：$?，执行的结果是$(($var4==100))"
fi

read age
read iq
if (( $age > 18 && $iq < 60))
then
	echo "返回状态是：$?，执行的结果是$(( $age > 18 && $iq < 60))"
fi
	
## if elif
### 同事也注意一下这里((num==1)) 和 (($num==1))
printf "Input integer number: "
read num
if (($num==1)); then
    echo "Monday"
elif (($num==2)); then
    echo "Tuesday"
elif (($num==3)); then
    echo "Wednesday"
elif ((num==4)); then
    echo "Thursday"
elif ((num==5)); then
    echo "Friday"
elif ((num==6)); then
    echo "Saturday"
elif ((num==7)); then
    echo "Sunday"
else
    echo "error"
fi
