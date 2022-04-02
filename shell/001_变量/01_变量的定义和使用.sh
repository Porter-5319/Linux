#!/bin/bash
echo "***********变量的使用和定义***********"
# 变量的定义
url=PythonMan # 第一种
echo $url
name='PythonMan' # 第二种
echo $name
author="PythonMan" # 第三种
echo $author


## 上面是三种变量定义的方法，他们之间有什么区别呢

### 先看第一种和(第二种,第三种)
#### 在有空格时，如果没有引号，则空格后面的不被解释。
url=PythonMan GH
echo $url
name='PythonMan GH'
echo $name
author="PtthonMan GH"
echo $author
#### 没有引号时空格后面的哪里去了呢？看下面
url=PythonMan name=GH # 我也不知道这算什么，自己想吧

### 第二种和第三种的区别
url=PythonMan
name='$url GH' # 此处不解析 $url
echo $name
author="$url GH" # 此处解析 #url
echo $author


# 变量的使用 
## 两种方法 $name  ${name}
url=PythonMan
echo $url
echo ${url}
## 两种方法的区别在于{}帮助解释器识别变量的边界
### 下面的第一个会把$urlGH当成一个整体
echo "$urlGH"
echo "${url}GH"



# 变量的赋值
## 一般的赋值 = 两边不能有空格
### 为什么 = 两边不能有空格呢？
#### var =value  脚本尝试运行一个叫var的命令，而且带着一个 "=value" 参数
#### var= value  脚本尝试运行一个叫value的命令，而且带着一个被赋值成""的环境变量"VARIABLE"

## 将命令的结果赋值给变量：两种方式`command` 和 $(command)
var=`hostname`
echo $var
var=$(hostname)
echo $var



# 定义只读变量
myUrl=PythonManGH
readonly myUrl
myUrl=PythonManGG



# 删除变量，不能删除只读变量
unset name
echo $name


