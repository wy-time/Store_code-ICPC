import math
e=math.exp(1.0)
n=input()
result=1
n=int(n)
for i in range(2,n+1):
    result*=i
result/=e
result%=998244353
result=round(result)
print (result)
