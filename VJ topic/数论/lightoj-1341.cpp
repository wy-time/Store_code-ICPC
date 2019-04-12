#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll maxn = 1e6 + 5;
ll prime[maxn];
void get_prime()
{
    ll i;
    wfor(i, 2, maxn)
    {
        if (!prime[i])
            prime[++prime[0]] = i;
        ll j;
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
    ll t;
    get_prime();
    cin >> t;
    ll casecnt = 0;
    while (t--)
    {
        casecnt++;
        ll sum = 1;
        ll ans = 0;
        ll a, b;
        cin >> a >> b;
        ll i;
        if (b > sqrt(a))
            ans = 0;
        else
        {
            ll temp = a;
            for (i = 1; i <= prime[0] && prime[i]*prime[i] <= a; i++)
            {
                if (a % prime[i] == 0)
                {
                    ll cnt = 0;
                    while (a % prime[i] == 0)
                    {
                        cnt++;
                        a /= prime[i];
                    }
                    sum *= (cnt + 1);
                }
            }
            if (a > 1)
                sum *= 2;
            a = temp;
            ans = sum / 2;
            ll fix = 0;
            for (i = 1; i * i <= a; i++)
            {
                if (i >= b)
                    break;
                if (a % i == 0)
                {
                    fix++;
                }
            }
            ans -= fix;
        }
        cout << "Case " << casecnt << ": " << ans << endl;
    }
    return 0;
}
