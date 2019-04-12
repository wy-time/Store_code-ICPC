#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//     char ch = getchar(); x = 0;
//     for (; ch < '0' || ch > '9'; ch = getchar());
//     for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 1e4 + 5;
const int INF = 0x7f7f7f7f;
struct EDGE
{
    int _end;
    int next;
    int w;
};
struct DIS
{
    int id;
    int dis;
    DIS(int a, int b)
    {
        id = a;
        dis = b;
    }
    bool operator <(DIS a) const
    {
        return dis > a.dis;
    }
};
struct node
{
    int id, f, g;
    node(int a, int b, int  c)
    {
        id = a;
        f = b;
        g = c;
    }
    bool operator <(node a) const
    {
        return f > a.f;
    }
};
int dis[maxn];
EDGE edge[10 * maxn], edge2[10 * maxn];
int head[maxn];
int head2[maxn];
void add(int beg, int end, int w, int &cnt, int mode);
int astar(int beg, int _end, int k);
void dij(int beg);
int main()
{
    std::ios::sync_with_stdio(false);
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
    int n, m;
    while (cin >> n >> m)
    {
        fill(dis + 1, dis + n + 1, INF);
        int s, e, k, t;
        cin >> s >> e >> k >> t;
        int i;
        int cnt = 0;
        int cnt2 = 0;
        wfor(i, 0, m)
        {
            int a, b, c;
            cin >> a >> b >> c;
            add(b, a, c, cnt, 1);
            add(a, b, c, cnt2, 2);
        }
        dij(e);
        int res = astar(s, e, k);
        if (res <= t)
            cout << "yareyaredawa" << endl;
        else
            cout << "Whitesnake!" << endl;
    }
    return 0;
}
int astar(int beg, int _end, int k)
{
    priority_queue<node>qu;
    qu.push(node(beg, dis[beg], 0));
    int i;
    int cnt = 0;
    while (!qu.empty())
    {
        node temp = qu.top();
        qu.pop();
        for (i = head2[temp.id]; i != 0; i = edge2[i].next)
        {
            qu.push(node(edge2[i]._end, dis[edge2[i]._end] + temp.g + edge2[i].w, temp.g + edge2[i].w));
        }
        if (temp.id == _end)
        {
            cnt++;
        }
        if (cnt == k)
            return temp.f;
    }
    return -1;
}
void add(int beg, int _end, int w, int &cnt, int mode)
{
    if (mode == 1)
    {
        edge[++cnt].next = head[beg];
        edge[cnt]._end = _end;
        edge[cnt].w = w;
        head[beg] = cnt;
    } else
    {
        edge2[++cnt].next = head2[beg];
        edge2[cnt]._end = _end;
        edge2[cnt].w = w;
        head2[beg] = cnt;
    }
}
void dij(int beg)
{
    priority_queue<DIS> qu;
    qu.push(DIS(beg, 0));
    int i;
    dis[beg] = 0;
    while (!qu.empty())
    {
        DIS temp = qu.top();
        qu.pop();
        beg = temp.id;
        for (i = head[beg]; i != 0; i = edge[i].next)
        {
            if (edge[i].w + dis[beg] < dis[edge[i]._end])
            {
                dis[edge[i]._end] = edge[i].w + dis[beg];
                qu.push(DIS(edge[i]._end, dis[edge[i]._end]));
            }
        }
    }
}
