#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
typedef long long LL;
const LL P = 1e9 + 7;
LL quick_mod(LL a, LL b, LL m)
{
    LL ans = 1;
    a %= m;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % m;
            b--;
        }
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}

struct T
{
    LL p, d;
};

LL w;

//二次域乘法
T multi_er(T a, T b, LL m)
{
    T ans;
    ans.p = (a.p * b.p % m + a.d * b.d % m * w % m) % m;
    ans.d = (a.p * b.d % m + a.d * b.p % m) % m;
    return ans;
}

//二次域上快速幂
T power(T a, LL b, LL m)
{
    T ans;
    ans.p = 1;
    ans.d = 0;
    while (b)
    {
        if (b & 1)
        {
            ans = multi_er(ans, a, m);
            b--;
        }
        b >>= 1;
        a = multi_er(a, a, m);
    }
    return ans;
}

//求勒让德符号
LL Legendre(LL a, LL p)
{
    return quick_mod(a, (p - 1) >> 1, p);
}

LL mod(LL a, LL m)
{
    a %= m;
    if (a < 0) a += m;
    return a;
}
LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL g = exgcd(b, a % b, x, y);
    LL t = x;
    x = y;
    y = t - a / b * y;
    return g;
}
LL Solve(LL n, LL p)
{
    if (p == 2) return 1;
    if (Legendre(n, p) + 1 == p)
        return -1;
    LL a = -1, t;
    while (true)
    {
        a = rand() % p;
        t = a * a - n;
        w = mod(t, p);
        if (Legendre(w, p) + 1 == p) break;
    }
    T tmp;
    tmp.p = a;
    tmp.d = 1;
    T ans = power(tmp, (p + 1) >> 1, p);
    return ans.p;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        LL B, C;
        LL n, p;
        scanf("%lld %lld", &B, &C);
        vector<LL> ans1;
        vector<LL> ans2;
        n = B * B - 4ll * C;
        p = 1000000007ll;
        if (n < 0)
            n = (n + P) % P;
        if (n == 0)
            ans1.push_back(0);
        else
        {
            n %= p;
            LL a = Solve(n, p);
            if (a == -1)
            {
                printf("-1 -1\n");
                continue;
            }
            LL b = p - a;
            if (a > b) swap(a, b);
            if (a == b)
            {
                ans1.push_back(a);
            }
            else
            {
                ans1.push_back(a);
                ans1.push_back(b);
            }
        }
        LL x, y;
        if (B == 0)
            ans2.push_back(P);
        else
        {
            exgcd(1, P, x, y);

            x = x * B;
            if (x < 0)
            {
                x = x % P + P;
            } else
                x = x % P;
            ans2.push_back(x);
            if (x < P)
                ans2.push_back(x + P);
        }
        unsigned int i, j;
        int flag = 0;
        LL resx = -1, resy = -1;
        for (i = 0; i < ans1.size(); i++)
        {
            if (flag == 1)
                break;
            for (j = 0; j < ans2.size(); j++)
            {
                LL t1 = ans1[i];
                LL t2 = ans2[j];
                if ((t1 + t2) % 2 == 0)
                {
                    resx = (t1 + t2) / 2;
                    resy = t2 - resx;
                    if (resx >= 0 && resx < P && resy >= 0 && resy < P)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag == 1)
        {
            if (resx > resy)
            {
                swap(resx, resy);
            }
            printf("%lld %lld\n", resx, resy);
        }
        else
        {
            printf("-1 -1\n");
        }
    }
    return 0;
}