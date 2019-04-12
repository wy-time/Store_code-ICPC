#include <iostream>
#include <cmath>
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
ll ksm(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
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
    cin >> n;
    ll num[20] = {0};
    ll ans = 1;
    ll temp = n;
    int cnt = 0;
    while (temp)
    {
        num[cnt++] = temp % 10;
        ans *= num[cnt - 1];
        temp /= 10;
    }
    int i;
    ll tans = 1;
    int te = 1;
    mfor(i, cnt - 1, 0)
    {
        if (num[i] == 0)
            break;
        if (i == cnt - 1)
            ans = max(ans, tans * (num[i] - 1 == 0 ? 1 : num[i] - 1) * ksm(9, cnt - te));
        else
            ans = max(ans, tans * (num[i] - 1) * ksm(9, cnt - te));
        te++;
        tans *= num[i];
    }
    cout << ans << endl;
    return 0;
}
