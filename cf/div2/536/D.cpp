#include <iostream>
#include <vector>
#include <queue>
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
const int maxn = 1e5 + 5;
const int INF = 0x7f7f7f7f;
vector<int>G[maxn];
int ans[maxn];
int vis[maxn];
void slove(int beg)
{
    priority_queue<int, vector<int>, greater<int>>qu;
    qu.push(beg);
    int i;
    int ccnt = 0;
    vis[beg] = 1;
    while (!qu.empty())
    {
        int u = qu.top();
        qu.pop();
        ans[ccnt++] = u;
        int sz = G[u].size();
        for (i = 0; i < sz; i++)
        {
            int v = G[u][i];
            if (!vis[v])
            {
                qu.push(v);
                vis[v] = 1;
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
    slove(1);
    wfor(i, 0, n)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
