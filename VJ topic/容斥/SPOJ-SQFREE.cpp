#include <iostream>
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
const ll maxn = 1e7 + 5;
int prime[maxn];
void get_prime()
{
    ll i;
    wfor(i, 2, maxn)
    {
        if (!prime[i])
            prime[++prime[0]] = i;
        ll j;
        for (j = 1; j <= prime[0] && 1ll * i * prime[j] < maxn; j++)
        {
            prime[prime[j]*i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int ccnt[maxn];
void dfs(ll pos, ll num, ll cnt)
{
    ccnt[num] = cnt & 1 ? 1 : -1;
    ll i;
    wfor(i, pos, prime[0] + 1)
    {
        ll temp = num * prime[i];
        if (temp > maxn)
            break;
        dfs(i + 1, temp, cnt + 1);
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
    cin >> t;
    get_prime();
    dfs(1, 1, 0);
    while (t--)
    {
        ll n;
        cin >> n;
        ll i;
        ll ans = 0;
        for (i = 2; i * i <= n; i++)
        {
            if (ccnt[i] != 0)
                ans += 1ll * ccnt[i] * n / (i * i);
        }
        cout << n - ans << endl;
    }
    return 0;
}
