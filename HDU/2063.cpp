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
const int maxn = 10005;
struct st
{
    int end;
    int next;
};
st edge[maxn];
int head[maxn];
int cnt;
int ismaching[maxn];
int vis[maxn];
void add(int beg, int end)
{
    edge[++cnt].next = head[beg];
    edge[cnt].end = end;
    head[beg] = cnt;
}
int dfs(int beg)
{
    int i;
    for (i = head[beg]; i; i = edge[i].next)
    {
        int v = edge[i].end;
        if (!vis[v])
        {
            vis[v] = 1;
            if (ismaching[v] == -1 || dfs(ismaching[v]))
            {
                ismaching[beg] = v;
                ismaching[v] = beg;
                return 1;
            }
        }
    }
    return 0;
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
    int n, m, k;
    while (cin >> k && k)
    {
        cnt = 0;
        memset(head, 0, sizeof(head));
        cin >> n >> m;
        int i;
        wfor(i, 0, k)
        {
            int u, v;
            cin >> u >> v;
            add(u, v + n);
            add(v + n, u);
        }
        int ans = 0;
        memset(ismaching, -1, sizeof(ismaching));
        wfor(i, 1, n + 1)
        {
            if (ismaching[i] == -1)
            {
                memset(vis, 0, sizeof(vis));
                if (dfs(i) == 1)
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
