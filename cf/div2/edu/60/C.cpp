#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int check(ll step, string s, ll begx, ll begy, ll endx, ll endy, int n)
{
    ll row = step / n;
    int cnt = count(s.begin(), s.end(), 'U');
    begy += cnt * row;
    cnt = count(s.begin(), s.end(), 'D');
    begy -= cnt * row;
    cnt = count(s.begin(), s.end(), 'L');
    begx -= cnt * row;
    cnt = count(s.begin(), s.end(), 'R');
    begx += cnt * row;
    ll last = step % n;
    int i;
    wfor(i, 0, last)
    {
        switch (s[i])
        {
        case 'U':
            begy++;
            break;
        case 'D':
            begy--;
            break;
        case 'L':
            begx--;
            break;
        case 'R':
            begx++;
            break;
        }
    }
    ll need = abs(endx - begx) + abs(endy - begy);
    if (need <= step)
        return 1;
    else
        return 0;
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
    int begx, begy, endx, endy;
    cin >> begx >> begy >> endx >> endy;
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll L = 1, R = 1e18;
    ll ans = R;
    while (L <= R)
    {
        ll mid = (L + R) >> 1;
        if (check(mid, s, begx, begy, endx, endy, n))
        {
            R = mid - 1;
            ans = min(ans, mid);
        } else
            L = mid + 1;
    }
    if (ans != 1e18)
    {
        cout << ans << endl;
    } else
        cout << -1 << endl;
    return 0;
}
