a=int(input())
b=int(input())
while(a%b!=0):
    c=a%b
    a=b
    b=c
print(b)
