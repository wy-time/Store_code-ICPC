#include <iostream>
#include <algorithm>
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
int numa[maxn];
int numb[maxn];
int check(int ans, int n, int m)
{
    int i;
    wfor(i, 0, m)
    {
        int pos = lower_bound(numa, numa + n, numb[i] + ans) - numa;
        if (pos != n)
        {
            if (numa[pos] == numb[i] + ans)
                return 0;
        }
    }
    return 1;
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
    int n, m;
    while (cin >> n >> m)
    {
        int i;
        wfor(i, 0, n)
        {
            cin >> numa[i];
        }
        wfor(i, 0, m)
        {
            cin >> numb[i];
        }
        sort(numa, numa + n);
        sort(numb, numb + m);
        int l = 0; int r = 1000;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(mid, n, m))
                r = mid - 1;
            else
                l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}
