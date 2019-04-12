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
    ll w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    ll ans = w1 + 2 * h1;
    ans += w2 + 2 * h2;
    if (w1 == w2)
    {
        ans += 4;
    } else
        ans += 5;
    if (abs(w1 - w2) >= 2)
        ans += abs(w1 - w2) - 1;
    cout << ans << endl;
    return 0;
}
