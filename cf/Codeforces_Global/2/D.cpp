#include <iostream>
#include <algorithm>
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
const ll maxn = 1e5 + 5;
ll num[maxn];
ll cha[maxn];
ll sum[maxn];
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
    ll i;
    cin >> n;
    wfor(i, 0, n)
    {
        cin >> num[i];
    }
    sort(num, num + n);
    wfor(i, 0, n - 1)
    {
        cha[i] = num[i + 1] - num[i];
    }
    sort(cha, cha + n - 1);
    sum[0] = cha[0];
    wfor(i, 1, n - 1)
    {
        sum[i] = sum[i - 1] + cha[i];
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        ll len = r - l + 1;
        ll ans = len;
        ll pos = upper_bound(cha, cha + n - 1, len) - cha;
        ans += sum[pos - 1];
        ans += len * (n - pos - 1);
        cout << ans << " ";
    }
    return 0;
}
