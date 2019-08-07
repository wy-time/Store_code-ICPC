#include <bits/stdc++.h>
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
typedef long long LL;
void read(LL &x) {
    char ch = getchar(); x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
using namespace std;
const int maxn = 100001;
const int MAX = 1e4 + 5;
int prime[MAX];
void get_prime()
{
    int i;
    wfor(i, 2, MAX)
    {
        if (prime[i] == 0)
            prime[++prime[0]] = i;
        int j;
        for (j = 1; j <= prime[0] && prime[j]*i < MAX; j++)
        {
            prime[prime[j]*i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int main() {
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
    freopen("/home/time/debug/debug/in", "r", stdin);
    freopen("/home/time/debug/debug/out", "w", stdout);
#endif
    LL x;
    LL t;
    get_prime();
    //scanf("%d",&t);
    read(t);
    while (t--) {
        read(x);
        if (x == 1) {
            puts("1");
            continue;
        }
        int i;
        int res = 100000000;
        for (i = 1; i <= prime[0] && prime[i]*prime[i] <= x; i++)
        {
            if (x % prime[i] == 0)
            {
                int cnt = 0;
                while (x % prime[i] == 0)
                {
                    cnt++;
                    x /= prime[i];
                }
                res = min(res, cnt);
                if (res == 1)
                    break;
            }
        }
        if (res == 1)
        {
            puts("1");
            continue;
        }
        if (x == 1) {
            printf("%d\n", res);
            continue;
        }
        LL temp = sqrt(x);
        if (temp * temp == x)
        {
            LL temp2 = sqrt(temp);
            if (temp2 * temp2 == temp)
                res = min(res, 4);
            else
                res = min(2, res);
        } else
        {
            temp = pow(x, 1.0 / 3.0);
            if (temp * temp * temp == x || (temp + 1) * (temp + 1) * (temp + 1) == x || (temp - 1) * (temp - 1) * (temp - 1) == x)
            {
                res = min(res, 3);
            } else
                res = 1;
        }
        printf("%d\n", res);
    }
    return 0;
}
