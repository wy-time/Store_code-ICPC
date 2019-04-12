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
    int w, h;
    cin >> w >> h;
    int u1, d1, u2, d2;
    cin >> u1 >> d1 >> u2 >> d2;
    int ans = 0;
    if (d1 < d2)
    {
        swap(d1, d2);
        swap(u1, u2);
    }
    int n = h - d1 + 1;
    ans = w;
    ans += (n) * h - (n * (n - 1)) / 2;
    ans = ans - u1 > 0 ? ans - u1 : 0;
    h = d1 - 1;
    n = h - d2 + 1;
    ans += (n) * h - (n * (n - 1)) / 2;
    ans = ans - u2 > 0 ? ans - u2 : 0;
    h = d2 - 1;
    n = h;
    ans += (n) * h - (n * (n - 1)) / 2;
    cout << ans << endl;
    return 0;
}
