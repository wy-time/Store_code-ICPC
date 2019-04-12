#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll maxn = 10005;
ll num[maxn];
ll prime[maxn];
ll vis[maxn];
ll cnt[maxn];
ll isvalue[maxn];
ll cal(ll a)
{
    ll ans = 1;
    ans = ans * (a - 1) * (a) * (a - 2) * (a - 3);
    ans /= 24ll;
    return ans;
}
void get_prime()
{
    ll i;
    wfor(i, 2, maxn)
    {
        if (!prime[i])
        {
            prime[++prime[0]] = i;
        }
        ll j;
        for (j = 1; j <= prime[0] && prime[j]*i < maxn; j++)
        {
            prime[prime[j]*i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    wfor(i, 2, maxn)
    {
        ll j;
        ll temp = i;
        ll tt = 0;
        ll flag = 1;
        for (j = 1; j <= prime[0] && prime[j]*prime[j] <= temp; j++)
        {
            if (temp % prime[j] == 0)
            {
                tt = 0;
                cnt[i]++;
                while (temp % prime[j] == 0)
                {
                    temp /= prime[j];
                    tt++;
                }
            }
            if (tt >= 2)
                flag = 0;
        }
        if (flag)
            isvalue[i] = 1;
        if (temp > 1)
            cnt[i]++;
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
    ll n;
    get_prime();
    while (cin >> n)
    {
        ll i;
        memset(vis, 0, sizeof(vis));
        ll ans = 0;
        ll Max = 0;
        wfor(i, 0, n)
        {
            cin >> num[i];
            vis[num[i]]++;
            Max = max(num[i], Max);
        }
        wfor(i, 2, Max + 1)
        {
            ll j;
            for (j = 2 * i; j <= Max; j += i)
                vis[i] += vis[j];

        }
        wfor(i, 2, Max + 1)
        {
            if (isvalue[i])
            {
                if (cnt[i] & 1)
                    ans += cal(vis[i]);
                else
                    ans -= cal(vis[i]);
            }
        }
        cout << cal(n) - ans << endl;
    }
    return 0;
}
