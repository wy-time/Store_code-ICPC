#include <iostream>
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
const int maxn = 100005;
const int INF = 0x7f7f7f7f;
struct EDGE
{
    int _end;
    int w;
    int next;
};
int head[maxn];
EDGE edge[maxn * 2];
int cnt = -1;
int cur[maxn];
void add(int beg, int _end, int w)
{
    edge[++cnt].next = head[beg];
    edge[cnt].w = w;
    edge[cnt]._end = _end;
    head[beg] = cnt;
}
int dfn[maxn];
int bfs(int beg, int _end)
{
    queue<int>qu;
    qu.push(beg);
    memset(dfn, -1, sizeof(dfn));
    dfn[beg] = 0;
    while (!qu.empty())
    {
        int tmp = qu.front();
        qu.pop();
        if (tmp == _end)
            return 1;
        int i;
        for (i = head[tmp]; i != -1; i = edge[i].next)
        {
            int v = edge[i]._end;
            if (dfn[v] != -1 || edge[i].w <= 0)continue;
            dfn[v] = dfn[tmp] + 1;
            qu.push(v);
        }
    }
    return dfn[_end];
}
int dfs(int beg, int _end, int flow)
{
    if (beg == _end || !flow)
        return flow;
    int ans = 0;
    for (int &i = cur[beg]; i != -1; i = edge[i].next)
    {
        int v = edge[i]._end;
        if (dfn[v] != dfn[beg] + 1 || edge[i].w <= 0)continue;
        int temp = dfs(v, _end, min(edge[i].w, flow));
        if (temp > 0)
        {
            ans += temp;
            edge[i].w -= temp;
            edge[i ^ 1].w += temp;
            flow -= temp;
            if (!flow) break;
        }
    }
    // if (flow == ans)dfn[beg] = -1;
    if (!ans)dfn[beg] = -1;
    return ans;
}
int dinic(int beg, int _end, int n)
{
    int ans = 0;
    while (bfs(beg, _end) != -1)
    {
        int i;
        wfor(i, 1, n + 1)
        {
            cur[i] = head[i];
        }
        int t = dfs(beg, _end, 0x7f7f7f7f);
        if (t > 0)
            ans += t;
    }
    return ans;
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
    int t;
    cin >> t;
    while (t--)
    {
        cnt = -1;
        memset(head, -1, sizeof(head));
        int n, m;
        cin >> n >> m;
        int i;
        int beg = 0, _end = 0;
        int maxx = -1, minx = INF;
        int x, y;
        wfor(i, 1, n + 1)
        {
            cin >> x >> y;
            if (x < minx)
            {
                beg = i;
                minx = x;
            }
            if (x > maxx)
            {
                _end = i;
                maxx = x;
            }
        }
        wfor(i, 0, m)
        {
            int u, v, w;
            cin >> u >> v >> w;
            add(u, v, w);
            add(v, u, w);
        }
        int ans = dinic(beg, _end, n);
        cout << ans << endl;
    }
    return 0;
}
