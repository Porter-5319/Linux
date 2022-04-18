#!/bin/bash

## 数组的定义 array_name=(ele1 ele2 ele3 ele4 ... elen)
### Shell 是弱类型的，它并不要求所有数组元素的类型必须相同
### Shell 数组的长度不是固定的，定义之后还可以增加元素
nums=(1 2 3 4 5 6 7 8 9)
array=(1 2 "PythonMan")
### 无需逐个元素地给数组赋值，可以直接给指定元素赋值
ages=([1]=1 [3]=3 [9]=9)


## 数组的使用
### 获取指定下标的数组 ${array_name[index]}
echo ${nums[2]}
### 获取数组中的所有元素,下标使用@ 和 *
#### 他们的区别是什么？
echo ${nums[*]}
echo ${nums[@]}


## 获取数组的长度
### 获取数组的长度 ${#arrary_name[@]} ${#array_name[*]}
echo ${#nums[@]}
echo ${#nums[*]}
### 获取某个元素的长度(获取字符串的长度)
echo ${#nums[0]}


## 删除数组元素 
### 删除指定元素 unset nums[index]
unset nums[5]
echo ${nums[@]}
### 删除整个数组 unset nums
unset nums
echo ${nums[@]}



## 数组拼接 
### array_new=(${array1[@]} ${array2[@]})
### array_new=(${array1[*]} ${array2[*]})
