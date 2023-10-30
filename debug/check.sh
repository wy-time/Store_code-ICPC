#!/bin/bash
g++ ./main.cpp -o debug
g++ ./std.cpp -o std
g++ ./rand.cpp -o rand
if [ $# -lt 1 ]; then
    while true;do
        ./rand>in
        ./debug<in>out
        ./std<in>stdout
        if diff out stdout;then
            echo "AC"
        else
            echo "WA"
            #cat out
            #echo -e "--------------------\n"
            #cat stdout
            exit 0
        fi
    done
else
    g++ ./spj.cpp -o spj
    while true;do
        ./rand>in
        ./debug<in>out
        ./std<in>stdout
        if [ $? -ne 0 ];then  #看std是否成功执行以判断数据是否合法
            continue
        fi
        ./spj<in
        if diff out stdout;then
            echo "AC"
        else
            echo "WA"
           # cat out
           # echo -e "--------------------\n"
           # cat stdout
            exit 0
        fi
    done
fi
