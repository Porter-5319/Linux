#!/bin/bash
echo "****************if grep 的使用****************"

## if grep 解释
### 如果某个文件中包含某个字符串
if grep "/cin/bash" 01_if和双小括号.sh
then
	echo "返回状态是 $?"
else
	echo "返回状态是 $?"
fi
