n = 0
_as = []
ns = []
flag = False
a1 = 0
a2 = 0
n1 = 0
n2 = 0


def exgcd(a, b, g, x, y):
    if(b == 0):
        g[0] = a
        x[0] = 1
        y[0] = 0
        return
    exgcd(b, a % b, g, y, x)
    y[0] -= (a//b)*x[0]


def abs(x):
    if(x > 0):
        return x
    else:
        return -x


def china():
    global a1
    global a2
    global n1
    global n2
    global flag
    g = [0]
    x = [0]
    y = [0]
    d = a2-a1
    exgcd(n1, n2, g, x, y)
    if(d % g[0] == 0):
        x[0] = ((x[0]*d//g[0]) % (n2//g[0])+(n2//g[0])) % (n2//g[0])
        a1 = x[0]*n1+a1
        n1 = (n1*n2)//g[0]
    else:
        flag = True


def realchina():
    global a1
    global a2
    global n1
    global n2
    global n
    global flag
    a1 = _as[0]
    n1 = ns[0]
    for i in range(len(_as)):
        a2 = _as[i]
        n2 = ns[i]
        china()
        if(flag is True):
            return -1
    return a1


def slove():
    global n
    global flag
    global _as
    global ns
    n, m = list(map(int, input().split()))
    flag = False
    for i in range(n):
        t1, t2 = list(map(int, input().split()))
        ns.append(t1)
        _as.append(t2)
    ans = realchina()
    if(ans > m):
        print("he was probably lying")
    elif (ans == -1):
        print("he was definitely lying")
    else:
        print(ans)


if __name__ == '__main__':
    slove()
