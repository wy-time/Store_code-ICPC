#include <iostream>
#include <queue>
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
const int maxn = 10005;
int num[maxn];
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
    int y = 0;
    wfor(i, 0, n)
    {
        int t;
        cin >> t;
        num[t]++;
        y = max(t, y);
    }
    for (i = 1; i <= y; i++)
    {
        if (y % i == 0)
        {
            num[i]--;
        }
    }
    int x = 0;
    wfor(i, 0, maxn)
    {
        if (num[i] != 0)
            x = max(x, i);
    }
    cout << x << " " << y << endl;
    return 0;
}
