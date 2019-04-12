#include <iostream>
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
const int maxn = 3e5 + 5;
int color[maxn];
vector <int>G[maxn];
struct st
{
    int blue;
    int red;
};
st point[maxn];
int vis[maxn];
int dft[maxn];
st dfs(int id, int step)
{
    vis[id] = 1;
    dft[id] = step;
    int siz = G[id].size();
    int i;
    st temp;
    temp.blue = temp.red = 0;
    wfor(i, 0, siz)
    {
        st ge;
        int v;
        v = G[id][i];
        if (!vis[v])
        {
            ge = dfs(v, step + 1);
            temp.blue += ge.blue;
            temp.red += ge.red;
        }
    }
    if (color[id] == 1)
    {
        temp.red++;
    } else if (color[id] == 2)
    {
        temp.blue++;
    }
    point[id] = temp;
    return point[id];
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
    cin >> n;
    int i;
    int sumcolor[3] = {0};
    wfor(i, 1, n + 1)
    {
        cin >> color[i];
        sumcolor[color[i]]++;
    }
    wfor(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    int ans = 0;
    int j;
    wfor(i, 1, n + 1)
    {
        int len = G[i].size();
        wfor(j, 0, len)
        {
            int v = G[i][j];
            int k = dft[i] < dft[v] ? v : i;
            if ((point[k].blue == sumcolor[2] && point[k].red == 0) || (point[k].red == sumcolor[1] && point[k].blue == 0))
            {
                ans++;
            }
        }
    }
    cout << ans / 2 << endl;
    return 0;
}
