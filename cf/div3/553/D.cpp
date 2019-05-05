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
struct st
{
    ll a;
    ll b;
};
struct rule
{
    bool operator ()(const st &x, const st&y)
    {
        return x.a - x.b > y.a - y.b;
    }
};
const ll maxn = 1e5 + 5;
st num[maxn];
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
    cin >> n;
    ll i;
    wfor(i, 0, n)
    {
        cin >> num[i].a >> num[i].b;
    }
    sort(num, num + n, rule());
    ll ans = 0;
    wfor(i, 0, n)
    {
        ans += num[i].a * i;
        ans += num[i].b * (n - i - 1);
    }
    cout << ans << endl;
    return 0;
}
