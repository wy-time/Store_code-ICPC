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
char ma[10][10];
int vis[10][10];
void gao(int i, int j, int n, int x, int step)
{
    int t = i;
    while (t >= 0 && ma[t][j] != 'X')
    {
        if (vis[t][j] == 0 || vis[t][j] == step)
            vis[t][j] = x;
        t--;
    }
    t = i;
    while (t < n && ma[t][j] != 'X')
    {
        if (vis[t][j] == 0 || vis[t][j] == step)
            vis[t][j] = x;
        t++;
    }
    t = j;
    while (t < n && ma[i][t] != 'X')
    {
        if (vis[i][t] == 0 || vis[i][t] == step)
            vis[i][t] = x;
        t++;
    }
    t = j;
    while (t >= 0 && ma[i][t] != 'X')
    {
        if (vis[i][t] == 0 || vis[i][t] == step)
            vis[i][t] = x;
        t--;
    }
}
int ans = 0;
void slove(int n, int step)
{
    int i, j;
    ans = max(ans, step);
    wfor(i, 0, n)
    {
        wfor(j, 0, n)
        {
            if (vis[i][j] == 0 && ma[i][j] != 'X')
            {
                gao(i, j, n, step, step);
                slove(n, step + 1);
                gao(i, j, n, 0, step);
            }
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
    int n;
    while (cin >> n && n)
    {
        int i, j;
        ans = 0;
        wfor(i, 0, n)
        {
            wfor(j, 0, n)
            {
                cin >> ma[i][j];
            }
        }
        memset(vis, 0, sizeof(vis));
        slove(n, 1);
        cout << ans - 1 << endl;
    }
    return 0;
}
