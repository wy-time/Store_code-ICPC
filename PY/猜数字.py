import random
answer =random.randint(1,10)
print("<------猜数字游戏------>")
guess=-1
while(guess!=answer):
    temp = input("输入你猜的数字")
    guess = int(temp)
    if guess ==answer:
        print("猜对了")
    else:
        if(guess>answer):
            print("错了,且大了")
        else:
            print("错了，且小了")
print("游戏结束")
