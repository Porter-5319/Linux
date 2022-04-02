#!/bin/bash

## ${#string_name} 获取字符串的长度
url="www.baidu.com"
echo ${#url}

## 字符串拼接
name=PythonMan
str1=$url$name # 中间不能有空格
echo $str1
str2="$url $name" # 此时可以有空格
echo $str2
str3=$url" : "$name # 中间可以有其它字符
echo $str3
str4="$url : $name" # 中间有空格也可以这么写
echo $str4
str5=${url}/xxx
echo $str5
str6="${url}/xxx"
echo $str6
str7="${url}Script : ${name}GH"
echo $str7



# 从指定位置截取
##从左边开始计数
### ${name:start:length} # 从哪儿开始，截取多少个字符
url1=${url:5:5}
echo $url1
### ${name:start} # 从哪里开始，截取到字符串末尾
url2=${url:5}
echo $url2

## 从右边开始计数
	### 从左边开始计数时，起始数字是 0（这符合程序员思维）；从右边开始计数时，起始数字是 1（这符合常人思维）。计数方向不同，起始数字也不同
	### 不管从哪边开始计数，截取方向都是从左到右
### ${name:0-start:length} 截取指定长度
echo ${url:0-5:6}
### ${name:0-start} 截取到末尾
echo ${url:0-5}


# 从子字符串开始截取
## 使用#号截取右边字符串，从左往右查找
### ${url#*chars} 其中，string 表示要截取的字符，chars 是指定的字符（或者子字符串），*是通配符的一种，表示任意长度的字符串。*chars连起来使用的意思是：忽略左边的所有字符，直到遇见 chars（chars 不会被截取）
url="http://c.biancheng.net/index.html"
echo ${url#*:} # 截取冒号后面的内容
echo ${url#*biancheng}
echo ${url#http://}
### ${url##*chars} 如果上面指定的字符串在变量中不止一个，而且希望从最后一个开始，则需要使用${url##*chars}，用法与${url#*chars}一样
url="---aa+++aa@@@"
echo ${url#*aa}
echo ${url##*aa}

## 使用%截取左边字符串，从右往左查找，用法与#相同，${name%chars*}注意语法的不同
url="http://c.biancheng.net/index.html"
echo ${url%/*} # 输出：http://c.biancheng.net
echo ${url%%/*} # 输出：http:

url="---aa+++aa@@@"
echo ${url%aa*}
echo ${url%%aa*}



# ${string: start :length}	从 string 字符串的左边第 start 个字符开始，向右截取 length 个字符。
# ${string: start}	        从 string 字符串的左边第 start 个字符开始截取，直到最后。
# ${string: 0-start :length}	从 string 字符串的右边第 start 个字符开始，向右截取 length 个字符。
# ${string: 0-start}	        从 string 字符串的右边第 start 个字符开始截取，直到最后。
# ${string#*chars}	        从 string 字符串第一次出现 *chars 的位置开始，截取 *chars 右边的所有字符。
# ${string##*chars}	        从 string 字符串最后一次出现 *chars 的位置开始，截取 *chars 右边的所有字符。
# ${string%*chars}	        从 string 字符串第一次出现 *chars 的位置开始，截取 *chars 左边的所有字符。
# ${string%%*chars}	        从 string 字符串最后一次出现 *chars 的位置开始，截取 *chars 左边的所有字符。

