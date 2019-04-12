#include <iostream>
#include <set>
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
const int maxn = 1005;
int vis[maxn];
struct st
{
    int end;
    int next;
};
st edge[maxn * 20];
int head[maxn];
int cnt;
void add(int beg, int end)
{
    edge[++cnt].next = head[beg];
    edge[cnt].end = end;
    head[beg] = cnt;
}
int have[maxn];
int dfs(int beg)
{
    int i;
    for (i = head[beg]; i; i = edge[i].next)
    {
        int v = edge[i].end;
        if (vis[v] == 0)
        {
            vis[v] = vis[beg] * -1;
            if (dfs(v) == 0)
                return 0;
        } else
        {
            if (vis[v] == vis[beg] * -1)
                continue;
            if (vis[v] < -1 && vis[beg] > 0)
            {
                vis[v] = -1;
                if (dfs(v) == 0)
                    return 0;
                continue;
            }
            if (vis[v] > 1 && vis[beg] < 0)
            {
                vis[v] = 1;
                if (dfs(v) == 0)
                    return 0;
                continue;
            }
            return 0;
        }
    }
    return 1;
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
    int n, m, x, y;
    while (cin >> n >> m >> x >> y)
    {
        set<pair<int, int>>st;
        cnt = 0;
        memset(vis, 0, sizeof(vis));
        memset(head, 0, sizeof(head));
        int i;
        wfor(i, 0, m)
        {
            int u, v;
            cin >> u >> v;
            if (st.count(make_pair(u, v)) == 0)
            {
                add(u, v);
                add(v, u);
                have[u] = 1;
                have[v] = 1;
                st.insert(make_pair(u, v));
                st.insert(make_pair(v, u));
            }
        }
        wfor(i, 0, x)
        {
            int t;
            cin >> t;
            vis[t] = 2;
        }
        wfor(i, 0, y)
        {
            int t;
            cin >> t;
            vis[t] = -2;
        }
        int flag = 1;
        wfor(i, 1, n + 1)
        {
            if (have[i] && vis[i] != -1 && vis[i] != 1)
            {
                if (vis[i] == 0)
                    vis[i] = 1;
                else if (vis[i] == 2)
                    vis[i] = 1;
                else
                    vis[i] = -1;
                if (dfs(i) == 0)
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
        {
            wfor(i, 1, n + 1)
            {
                if (vis[i] == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } else
            cout << "NO" << endl;
    }
    return 0;
}
