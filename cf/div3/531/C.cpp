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
const int maxn = 1005;
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
    int n, x, y;
    cin >> n >> x >> y;
    int i;
    int cnt = 0;
    wfor(i, 0, n)
    {
        cin >> num[i];
        if (num[i] <= x)
            cnt++;
    }
    if (x > y)
        cout << n << endl;
    else
    {
        if (cnt % 2 == 0)
            cout << cnt / 2 << endl;
        else
            cout << cnt / 2 + 1 << endl;
    }
    return 0;
}
