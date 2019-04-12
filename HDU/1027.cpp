#include <iostream>
#include <cstring>
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
int vis[1005];
int ans[1005];
int cnt;
void dfs(int n, int m, int step)
{
    int i;
    if (step == n)
    {
        cnt++;
        return;
    }
    wfor(i, 1, n + 1)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            ans[step] = i;
            dfs(n, m, step + 1);
            if (cnt == m)
            {
                return;
            }
            vis[i] = 0;
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
    while (cin >> n >> m)
    {
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        dfs(n, m, 0);
        int i;
        wfor(i, 0, n - 1)
        {
            cout << ans[i] << " ";
        }
        cout << ans[i] << endl;
    }
    return 0;
}
