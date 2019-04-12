#include <iostream>
#include <queue>
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
const int maxn = 2e5 + 5;
vector<int>G[maxn];
int deg[maxn];
int vis[maxn];
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
    int maxpoint = 0;
    int maxdeg = 0;
    wfor(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++;
        deg[v]++;
        if (maxdeg < max(deg[u], deg[v]))
        {
            maxdeg = max(deg[u], deg[v]);
            maxpoint = deg[u] > deg[v] ? u : v;
        }
    }
    int sz = G[maxpoint].size();
    vis[maxpoint] = 1;
    queue<int>qu;
    int cnt = 1;
    wfor(i, 0, sz)
    {
        int v = G[maxpoint][i];
        vis[v] = 1;
        cnt++;
        qu.push(v);
        cout << maxpoint << " " << v << endl;
    }
    while (!qu.empty() && cnt < n)
    {
        int u = qu.front();
        qu.pop();
        int len = G[u].size();
        wfor(i, 0, len)
        {
            int v = G[u][i];
            if (!vis[v])
            {
                qu.push(v);
                cnt++;
                vis[v] = 1;
                cout << u << " " << v << endl;
            }
        }
    }
    return 0;
}
