#include <iostream>
#include<queue>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int INF = 0x7f7f7f7f;
const int maxn = 100005;
struct EDGE
{
    int first;
    int _end;
    int w;
    int next;
    int cost;
};
struct PO
{
    int x;
    int y;
    PO(int a, int b)
    {
        x = a;
        y = b;
    }
    PO() {}
};
int pre[maxn];
int dis[maxn];
int n, m;
int head[maxn];
EDGE edge[maxn];
int cnt = -1;
void add(int beg, int _end, int w, int cost)
{
    edge[++cnt].next = head[beg];
    edge[cnt].w = w;
    edge[cnt]._end = _end;
    edge[cnt].cost = cost;
    edge[cnt].first = beg;
    head[beg] = cnt;
}
int spfa(int beg, int _end)
{
    int vis [maxn] = {0};
    queue <int> qu;
    qu.push(beg);
    vis[beg] = 1;
    dis[beg] = 0;
    while (!qu.empty())
    {
        int temp = qu.front();
        qu.pop();
        vis[temp] = 0;
        int i;
        for (i = head[temp]; i != -1; i = edge[i].next)
        {
            int v = edge[i]._end;
            if (edge[i].w <= 0 || vis[i])continue;
            if (edge[i].cost + dis[temp] < dis[v])
            {
                pre[v] = i;
                dis[v] = edge[i].cost + dis[temp];
                qu.push(v);
                vis[v] = 1;
            }
        }
    }
    return dis[_end];
}
int min_cost(int beg, int _end)
{
    memset(pre, -1, sizeof(pre));
    int ans = 0;
    while (spfa(beg, _end) != INF)
    {
        fill(dis, dis + maxn, INF);
        int t = pre[_end];
        while (t != -1)
        {
            ans += edge[t].cost;
            edge[t].w -= 1;
            edge[t ^ 1].w += 1;
            t = pre[edge[t].first];
        }
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
    while (cin >> n >> m)
    {
        memset(head, -1, sizeof(head));
        int i, j;
        if (n == 0 && m == 0)
        {
            break;
        }
        vector<PO>people;
        vector<PO>home;
        int p1 = 0, h1 = 0;
        wfor(i, 0, n)
        {
            wfor(j, 0, m)
            {
                char c;
                cin >> c;
                if (c == 'm')
                {
                    people.push_back(PO(i, j));
                    p1++;
                }
                if (c == 'H')
                {
                    home.push_back(PO(i, j));
                    h1++;
                }
            }
        }
        wfor(i, 0, p1)
        {
            add(0, i + 1, 1, 0);
            add(i + 1, 0, 0, 0);
        }
        wfor(j, 0, h1)
        {
            add(j + i + 1, p1 + h1 + 1, 1, 0);
            add(p1 + h1 + 1, j + i + 1, 0, 0);
        }
        wfor (i, 0, p1)
        {
            wfor (j, 0, h1)
            {
                int d = abs((double)(people[i]).x - (home[j]).x) + abs((double)(people[i]).y - (home[j]).y);
                add(i + 1, j + p1 + 1, INF, d);
                add(j + p1 + 1, i + 1, 0, -d);
            }
        }
        int ans = min_cost(0, h1 + p1 + 1);
        cout << ans << endl;
    }
    return 0;
}