// #include <iostream>
// #include <cstdio>
// #include <cstring>
// using namespace std;
// typedef long long ll;
// #define wfor(i,j,k) for(i=j;i<k;++i)
// #define mfor(i,j,k) for(i=j;i>=k;--i)
// // void read(ll &x) {
// //  char ch = getchar(); x = 0;
// //  for (; ch < '0' || ch > '9'; ch = getchar());
// //  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// // }
// const ll maxn = 10005;
// ll num[maxn];
// ll prime[maxn];
// ll isprime[maxn];
// ll vis[maxn];
// ll cnt[maxn];
// ll cal(ll a)
// {
//     ll ans = 1;
//     ans = ans * (a - 1) * (a) * (a - 2) * (a - 3);
//     ans /= 24ll;
//     return ans;
// }
// void get_prime()
// {
//     ll i;
//     wfor(i, 2, maxn)
//     {
//         if (!prime[i])
//         {
//             prime[++prime[0]] = i;
//             isprime[i] = 1;
//         }
//         ll j;
//         for (j = 1; j <= prime[0] && prime[j]*i < maxn; j++)
//         {
//             prime[prime[j]*i] = 1;
//             if (i % prime[j] == 0)
//                 break;
//         }
//     }
//     wfor(i, 2, maxn)
//     {
//         ll j;
//         ll temp = i;
//         for (j = 1; j <= prime[0] && prime[j]*prime[j] <= temp; j++)
//         {
//             if (temp % prime[j] == 0)
//             {
//                 cnt[i]++;
//                 while (temp % prime[j] == 0)
//                     temp /= prime[j];
//             }
//         }
//         if (temp > 1)
//             cnt[i]++;
//     }
// }
// int main()
// {
//     std::ios::sync_with_stdio(false);
// // #ifdef test
// //     freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// // #endif
// // #ifdef ubuntu
// //     freopen("/home/time/debug/debug/in", "r", stdin);
// //     freopen("/home/time/debug/debug/out", "w", stdout);
// // #endif
//     ll n;
//     get_prime();
//     while (cin >> n)
//     {
//         ll i;
//         memset(vis, 0, sizeof(vis));
//         ll ans = 0;
//         ll Max = 0;
//         wfor(i, 0, n)
//         {
//             cin >> num[i];
//             vis[num[i]]++;
//             Max = max(num[i], Max);
//         }
//         wfor(i, 2, Max + 1)
//         {
//             ll j;
//             for (j = 2 * i; j <= Max; j += i)
//                 vis[i] += vis[j];

//         }
//         wfor(i, 2, Max + 1)
//         {
//             if (isprime[i])
//             {
//                 if (cnt[i] & 1)
//                     ans += cal(vis[i]);
//                 else
//                     ans -= cal(vis[i]);
//             }
//         }
//         cout << cal(n) - ans << endl;
//     }
//     return 0;
// }

#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
// #include <bitset>
#include <list>
#include <stack>
#include <vector>
#include <math.h>
#include <string.h>
#include <queue>
#include <string>
#include <stdlib.h>
#include <algorithm>
//#define LL __int64
//#define LL long long
#define eps 1e-9
#define PI acos(-1.0)
typedef long long LL;
using namespace std;

const int maxn = 10010;

int p_num[maxn];
bool flag[maxn];
int sef[maxn];

LL num[maxn];

LL cal(LL n)
{
    long long tmp = n;
    return tmp * (tmp - 1LL) * (tmp - 2LL) * (tmp - 3LL) / (24LL);
}

void init()
{
    memset(flag, false, sizeof(flag));
    memset(p_num, 0, sizeof(p_num));

    for (int i = 1; i < maxn; i++)
        sef[i] = 1;

    for (int i = 2; i < maxn; i++)
    {
        if (flag[i] == false)
        {
            for (int j = i; j < maxn; j += i)
            {
                sef[j] *= i;
                p_num[j]++;
                if (j != i)
                    flag[j] = true;
            }
        }
    }
}

int main()
{
    LL n;
    LL a[maxn];
    LL num[maxn];
    init();
    while (~scanf("%lld", &n))
    {
        memset(num, 0, sizeof(num));
        LL Max = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
            num[a[i]] ++;
            Max = max(Max, a[i]);
        }
        if (n < 4)
        {
            printf("0\n");
            continue;
        }
        for (int i = 2; i <= Max; i++)
        {
            for (int j = i + i; j <= Max; j += i)
                num[i] += num[j];
        }

        LL ans = 0;

        for (LL i = 2; i <= Max; i++)
        {
            if (sef[i] == i)
            {
                if (p_num[i] & 1)
                    ans += cal(num[i]);
                else
                    ans -= cal(num[i]);
            }
        }
        ans = cal(n) - ans;
        printf("%lld\n", ans);
    }
    return 0;
}
