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
const int maxn = 1e5 + 5;
struct st
{
    int l, r;
    int id;
};
struct rule
{
    bool operator()(const st &x, const st &y)
    {
        if (x.l == y.l)
            return x.r < y.r;
        return x.l < y.l;
    }
};
st num[maxn];
int ans[maxn];
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
    int q;
    cin >> q;
    while (q--)
    {
        int vis[2] = {0};
        int n;
        cin >> n;
        int i;
        wfor(i, 0, n)
        {
            cin >> num[i].l >> num[i].r;
            num[i].id = i;
        }
        sort(num, num + n, rule());
        ans[num[0].id] = 1;
        vis[0] = 1;
        int l1 = num[0].l, r1 = num[0].r;
        wfor(i, 1, n)
        {
            int l = max(l1, num[i].l);
            int r = min(r1, num[i].r);
            if (l <= r)
            {
                ans[num[i].id] = 1;
                vis[0] = 1;
                l1 = min(l1, num[i].l);
                r1 = max(r1, num[i].r);
            } else
            {
                ans[num[i].id] = 2;
                vis[1] = 1;
            }
        }
        if (vis[0] && vis[1])
        {
            wfor(i, 0, n)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        } else
            cout << -1 << endl;
    }
    return 0;
}
