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
const int maxn = 1000;
char ma[maxn][maxn];
int vis[maxn][maxn];
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
    int n = 0, m = 0, k = 0;
    while (cin >> n >> m >> k)
    {
        memset(vis, 0, sizeof(vis));
        if (n == 0 && m == 0 && k == 0)
            break;
        int i, j;
        wfor(i, 0, n)
        {
            wfor(j, 0, m)
            {
                cin >> ma[i][j];
            }
        }
        int begx = 0;
        int begy = k - 1;
        int cnt = 0;
        vis[begx][begy] = 1;
        int loop = 0;
        while (1)
        {
            cnt++;
            int x = begx, y = begy;
            switch (ma[begx][begy])
            {
            case 'N':
                begx -= 1;
                break;
            case 'S':
                begx += 1;
                break;
            case 'W':
                begy -= 1;
                break;
            case 'E':
                begy += 1;
                break;
            }
            if (begx >= 0 && begx < n && begy >= 0 && begy < m)
            {
                if (vis[begx][begy] == 0)
                {
                    vis[begx][begy] = vis[x][y] + 1;
                } else
                {
                    loop = cnt - vis[begx][begy] + 1;
                    break;
                }
            } else
                break;
        }
        if (loop != 0)
        {
            cout << cnt - loop << " step(s) before a loop of " << loop << " step(s)" << endl;
        } else
            cout << cnt << " step(s) to exit" << endl;
    }
    return 0;
}
