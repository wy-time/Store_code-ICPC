#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
//     char ch = getchar(); x = 0;
//     for (; ch < '0' || ch > '9'; ch = getchar());
//     for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll maxn = 1e5 + 5;
ll num[maxn];
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
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll ans = k;
        ll i;
        wfor(i, 0, n)
        {
            cin >> num[i];
            ans += num[i];
        }
        sort(num, num + n, greater<ll>());
        ll m = 1;
        vector<ll>v;
        wfor(i, 0, n)
        {
            m += num[i] / k;
            v.push_back(k - num[i] % k);
        }
        sort(v.begin(), v.end());
        wfor(i, 0, max(n - m, 0ll))
        ans += v[i];
        cout << ans << endl;
    }
    return 0;
}