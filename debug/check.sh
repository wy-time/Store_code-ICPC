#!/bin/bash
g++ ./main.cpp -o debug
g++ ./std.cpp -o std
g++ ./rand.cpp -o rand
while true;do
    ./rand>in $RANDOM
    ./debug<in>out
    ./std<in>stdout
    if diff out stdout;then
        echo "AC"
    else
        echo "WA"
        cat out
        echo -e "--------------------\n"
        cat stdout
        exit 0
    fi
done
