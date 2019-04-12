#include <iostream>
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
int prime[maxn];
void get_prime()
{
    int i;
    wfor(i, 2, maxn)
    {
        if (!prime[i])
            prime[++prime[0]] = i;
        int j;
        for (j = 1; j <= prime[0] && prime[j]*i < maxn; j++)
        {
            prime[prime[j]*i] = 1;
            if (i % prime[j] == 0)
                break;
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
    ll n, b;
    cin >> n >> b;
    get_prime();
    int i;
    ll ans = 1e18;
    wfor(i, 1, prime[0] + 1)
    {
        ll cnt = 0;
        if (b == 1 || b < prime[i])
            break;
        if (b % prime[i] == 0)
        {
            while (b % prime[i] == 0)
            {
                b /= prime[i];
                cnt++;
            }
            ll t = n;
            ll cnt2 = 0;
            while (t)
            {
                cnt2 += t / prime[i];
                t /= prime[i];
            }
            ans = min(ans, cnt2 / cnt);
        }
    }
    if (b > 1)
    {
        ll t = n;
        ll cnt2 = 0;
        while (t)
        {
            cnt2 += t / b;
            t /= b;
        }
        ans = min(ans, cnt2 / 1);
    }
    cout << ans << endl;
    return 0;
}
