#!/bin/bash
# "" 双引号不会解释引号中的特殊字符，但是 $ `(后置引用) \(转义) 除外
var="a variable containing five words"
# COMMAND This is $var 执行COMMAND命令，后面带7个参数 "This" "is" "a" "variable" "containning" "five" "words"
# COMMAND "This is $var" 执行COMMAND命令，后面带一个参数
var2=""
# COMMAND $var2 $var2 $var2 COMMAND将不带参数执行
# COMMAND "$var2" "$var2" "$var2" 将以三个空参数执行
# COMMAND "$var2 $var2 $var2" 将以一个空参数执行


var="'(]\\{}\$\""
echo $var # '(]\{}$"
echo "$var" # '(]\{}$" 和上一句没什么区别.Doesn't make a difference.
echo
IFS='\' # 没搞明白IFS的意义
echo $var # '(] {}$" \ 字符被空白符替换了, 为什么?
echo "$var" # '(]\{}$"

# '' 单引号：不解释任何特殊字符的使用包括 $ 和转义字符
# 无法在单引号中显示一个单引号
echo "Why can't I write 's between single quites"
echo 'Why can'\''t I write '"'"'s between single quotes'
# 因此上面的内容是分为一下几个部分
# 'Why can' + \' + 't I write ' + "'" + 's between single quotes'

echo "hello!"
