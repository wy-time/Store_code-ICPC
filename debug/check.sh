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
