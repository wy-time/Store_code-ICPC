#include <iostream>
#include <iomanip>
#include <vector>
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
const int maxn = 105;
const double eps = 1e-12;
vector<int>G[maxn];
double ans;
void dfs(int beg, int now, int last, double mul, int step)
{
    if (mul * step < eps && step != 0)
        return ;
    if (now == beg && step != 0)
    {
        ans = ans + mul * step;
        return;
    }
    int num = G[now].size();
    if (last != 0)
    {
        num--;
    }
    int i;
    int sz = G[now].size();
    wfor(i, 0, sz)
    {
        int v = G[now][i];
        if (v != last)
        {
            dfs(beg, v, now, mul * 1.0 / num, step + 1);
        }
    }
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
    cin >> n >> m;
    int i;
    wfor(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    wfor(i, 1, n + 1)
    {
        ans = 0;
        dfs(i, i, 0, 1, 0);
        cout << fixed << setprecision(12) << ans << endl;
    }
    return 0;
}
