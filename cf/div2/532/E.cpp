#include <iostream>
#include <vector>
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
const int maxn = 1e5 + 5;
struct st
{
    int end;
    int beg;
    int next;
    int w;
};
vector<int>G[maxn];
st edge[maxn];
int head[maxn];
int cnt;
vector<int>res;
void add(int beg, int end, int w)
{
    edge[++cnt].next = head[beg];
    edge[cnt].end = end;
    edge[cnt].beg = beg;
    edge[cnt].w = w;
    head[beg] = cnt;
}
int deg[maxn];
int tp[maxn];
int toop(int mid, int n)
{
    int i;
    int num = 0;
    memset(tp, 0, sizeof(tp));
    memset(deg, 0, sizeof(deg));
    wfor(i, 1, n + 1)
    G[i].clear();
    wfor(i, 1, cnt + 1)
    {
        if (mid < edge[i].w)
        {
            deg[edge[i].end]++;
            G[edge[i].beg].push_back(edge[i].end);
        }
    }
    queue<int>qu;
    wfor(i, 1, n + 1)
    {
        if (deg[i] == 0)
        {
            qu.push(i);
            tp[i] = ++num;
        }
    }
    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        wfor(i, 0, G[u].size())
        {
            int v = G[u][i];
            deg[v]--;
            if (deg[v] == 0)
            {
                qu.push(v);
                tp[v] = ++num;
            }
        }
    }
    if (num == n)
        return 1;
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
    int n, m;
    cin >> n >> m;
    int i;
    wfor(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        deg[v]++;
    }
    int l, r;
    l = 0, r = 1e9;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (toop(mid, n))
            r = mid - 1;
        else
            l = mid + 1;
    }
    toop(l, n);
    int rescost = 0;
    wfor(i, 1, cnt + 1)
    {
        if (edge[i].w <= l && tp[edge[i].end] < tp[edge[i].beg])
        {
            rescost = max(rescost, edge[i].w);
            res.push_back(i);
        }
    }
    cout << rescost << " " << res.size() << endl;
    for (auto it : res)
        cout << it << " ";
    return 0;
}
