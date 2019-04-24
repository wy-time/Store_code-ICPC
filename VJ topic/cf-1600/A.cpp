#include <iostream>
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
struct st
{
    int end;
    int next;
};
st edge[maxn * 2];
int head[maxn];
int cnt;
int vis[maxn];
void add(int beg, int end)
{
    edge[++cnt].next = head[beg];
    edge[cnt].end = end;
    head[beg] = cnt;
}
int ans;
int dfn[maxn];
int father[maxn];
void dfs(int beg)
{
    int i;
    for (i = head[beg]; i; i = edge[i].next)
    {
        int v = edge[i].end;
        if (!dfn[v])
        {
            dfn[v] = dfn[beg] + 1;
            father[v] = beg;
            dfs(v);
        }
    }
}
int slove(int beg, int sum)
{
    int i;
    vis[beg] = 1;
    sum++;
    for (i = head[beg]; i; i = edge[i].next)
    {
        int v = edge[i].end;
        if (!vis[v] && dfn[v] > dfn[beg])
        {
            sum += slove(v, 0);
        }
    }
    if (sum % 2 == 0)
    {
        if (father[beg] != beg)
            ans++;
    }
    return sum;
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
    wfor(i, 1, n)
    {
        int u, k;
        cin >> u >> k;
        add(u, k);
        add(k, u);
    }
    if (n % 2 != 0)
    {
        cout << -1 << endl;
    } else
    {
        dfn[1] = 1;
        father[1] = 1;
        dfs(1);
        slove(1, 0);
        cout << ans << endl;
    }
    return 0;
}
