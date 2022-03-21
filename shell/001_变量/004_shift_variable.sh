#!/bin/bash
# 使用shift命令重新分配位置参数
# shift命令不会重新分配 $0
until [ -z "$1" ]
do
	echo -n "$1"
	shift
done
