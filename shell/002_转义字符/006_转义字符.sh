#!/bin/bash
## 使用 -e 转义
echo "\v\v\v\v" # 不会识别成转义字符
echo -e "\v\v\v\v" # 会识别成转义
echo "\042" # 不会转义成 "
echo -e "\042" # 042:引号 会做转义处理

## 使用$'\xxx'
echo "*********** 使用$'' 转义 *************"
echo $'\v\v\v\v'
echo $'\t \042 \t'
var=$'\042'
echo "$var This is a quoted string"
var=$'\137 \137 \137' # 137是八进制的
echo "$var This is a quoted string"
var=$'\101\102\103\010'
echo "The value of var = $var"

## 常用字符转义
### \"
var="\"Hello\",he said."
echo "The value of var = $var"
### \$
echo "\$var" # 输出结果：$var
### \\
echo "\\" # 输出结果：\

## 简单转义引用和命令替换
## *** \的行为依赖于它自身是否被转义
echo \z # z
echo \\z # \z
echo '\z' # \z
echo '\\z' # \\z
echo "\z" # \z 自身没有被转义
echo "\\z" # \z 自身被转转义

echo `echo \z` # z
echo `echo \\z` # z
### 上面等同于 echo \z
echo `echo \\\z` # \z
echo `echo "\\z"` # \z

## 转义一个空格会导致的问题
file_list="/bin/cat /bin/gzip /bin/more /usr/bin/less /usr/bin/emacs-20.7"
ls -l /sbin/dump $file_list # 这样没问题
ls -l /sbin/dump\ $file_list # 这里对空格转义会导致分割出现问题
## 转义字符提供续航功能
echo "foo
bar" # 打印两行
echo 'foo
bar' # 打印两行
echo foo\
	bar # 打印一行
echo "foo \
bar" # 打印一行
echo 'foo \
bar' # 打印两行，这里''不会解释\



