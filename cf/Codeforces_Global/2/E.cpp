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
const int maxn = 3e5 + 5;
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
    int n;
    cin >> n;
    int i;
    ll ans = 0;
    ll cnt1 = 0;
    wfor(i, 0, n)
    {
        cin >> num[i];
    }
    wfor(i, 0, n)
    {
        if (cnt1 == 0)
        {
            ans += num[i] / 3;
            num[i] %= 3;
            cnt1 += num[i];
        } else
        {
            if (num[i] >= 2)
            {
                ans += min(num[i] / 2, cnt1);
                ll temp = cnt1;
                cnt1 -= min(cnt1, num[i] / 2);
                num[i] -= min(num[i] / 2, temp) * 2;
                ans += num[i] / 3;
                num[i] %= 3;
                cnt1 += num[i];
            } else
                cnt1 += num[i];
        }
    }
    cout << ans << endl;
    return 0;
}
