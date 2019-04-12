#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 2e6 + 5;
int elu[maxn];
int prime[maxn];
void get_prime()
{
    int i;
    wfor(i, 2, maxn)
    {
        if (!prime[i])
        {
            prime[++prime[0]] = i;
        }
        int j;
        for (j = 1; j <= prime[0] && prime[j]*i < maxn; j++)
        {
            prime[prime[j]*i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void get_elu()
{
    int i;
    elu[1] = 0;
    wfor(i, 2, maxn)
    {
        elu[i] = i;
    }
    wfor(i, 2, maxn)
    {
        if (elu[i] == i)
        {
            int j;
            for (j = i; j < maxn; j += i)
            {
                elu[j] = elu[j] / i * (i - 1);
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
    freopen("/home/time/debug/debug/in", "r", stdin);
    freopen("/home/time/debug/debug/out", "w", stdout);
#endif
    int t;
    get_elu();
    get_prime();
    cin >> t;
    int casecnt = 0;
    while (t--)
    {
        casecnt++;
        int n;
        cin >> n;
        int i;
        ll ans = 0;
        wfor(i, 0, n)
        {
            int num;
            cin >> num;
            int r = upper_bound(prime + 1, prime + 1 + prime[0], num) - prime;
            int l;
            if (r != 1)
                l = prime[r - 1];
            else
                l = 1;
            r = prime[r];
            int j;
            wfor(j, l, r + 1)
            {
                if (elu[j] >= num)
                {
                    ans += j;
                    break;
                }
            }
        }
        cout << "Case " << casecnt << ": " << ans << " Xukha" << endl;
    }
    return 0;
}
