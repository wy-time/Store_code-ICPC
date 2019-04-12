#include <iostream>
#include <cstring>
#include <queue>
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
const int maxn = 3000 + 5;
int pre[maxn];
struct EDGE
{
    int v;
    int next;
};
int head[maxn];
EDGE edge[1000005];
int cnt;
void add_edge(int u, int v)
{
    edge[++cnt].next = head[u];
    edge[cnt].v = v;
    head[u] = cnt;
}
int findx(int x)
{
    int i = x;
    while (pre[i] != i)
    {
        i = pre[i];
    }
    int j;
    while (pre[x] != i)
    {
        j = pre[x];
        pre[x] = i;
        x = j;
    }
    return i;
}
void add(int u, int v)
{
    int a = findx(u);
    int b = findx(v);
    pre[b] = a;
}
int toop[maxn];
int indeg[maxn];
int ans[maxn];
int vis[maxn];
int toopcnt;
char ma[1005][1005];
int toop_sort(int n)
{
    queue<int>qu;
    int i;
    wfor(i, 0, maxn)
    {
        if (indeg[i] == 0 && vis[i])
        {
            qu.push(i);
            toop[toopcnt++] = i;
        }
    }
    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for (i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].v;
            indeg[v]--;
            if (indeg[v] == 0)
            {
                toop[toopcnt++] = v;
                qu.push(v);
            }
        }
    }
    if (toopcnt == n)
        return 1;
    else
        return 0;
}
int G[2005][2005];
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
    int i, j;
    int num = n + m;
    wfor(i, 0, maxn)
    {
        pre[i] = i;
    }
    int flag = 1;
    wfor(i, 0, n)
    {
        wfor(j, 0, m)
        {
            cin >> ma[i][j];
        }
    }
    wfor(i, 0, n)
    {
        wfor(j, 0, m)
        {
            char c = ma[i][j];
            if (c == '=')
            {
                int a = findx(i);
                int b = findx(j + 1001);
                if (vis[b] == 1)
                    swap(a, b);
                if (a != b)
                {
                    add(a, b);
                    num--;
                }
                vis[a] = 1;
            }
        }
    }
    wfor(i, 0, n)
    {
        wfor(j, 0, m)
        {
            char c = ma[i][j];
            if (c == '>')
            {
                int u = findx(i);
                int v = findx(j + 1001);
                if (G[u][v] == 0)
                {
                    add_edge(u, v);
                    G[u][v] = 1;
                    indeg[v]++;
                    vis[u] = 1;
                    vis[v] = 1;
                }
            } else if (c == '<')
            {
                int v = findx(i);
                int u = findx(j + 1001);
                if (G[u][v] == 0)
                {
                    add_edge(u, v);
                    G[u][v] = 1;
                    indeg[v]++;
                    vis[u] = 1;
                    vis[v] = 1;
                }
            }
        }
    }
    flag = toop_sort(num);
    if (flag == 0)
        cout << "No" << endl;
    else
    {
        cout << "Yes" << endl;
        int res = 1;
        ans[toop[toopcnt - 1]] = res;
        mfor(i, toopcnt - 2, 0)
        {
            if (G[toop[i]][toop[i + 1]] == 1)
                res++;
            ans[toop[i]] = res;
        }
        wfor(i, 0, n - 1)
        {
            ans[i] = ans[findx(i)];
            cout << ans[i] << " ";
        }
        cout << ans[findx(i)] << endl;
        wfor(i, 1001, 1001 + m - 1)
        {
            ans[i] = ans[findx(i)];
            cout << ans[i] << " ";
        }
        cout << ans[findx(i)] << endl;
    }
    return 0;
}
