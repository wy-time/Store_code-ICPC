#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <map>
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
struct EGDE
{
    int _end;
    int w;
    int next;
};
EGDE edge[maxn];
int head[maxn];
int cnt = -1;
int dft[maxn];
void add(int beg, int _end, int w)
{
    edge[++cnt].next = head[beg];
    edge[cnt].w = w;
    edge[cnt]._end = _end;
    head[beg] = cnt;
}
struct st
{
    string name;
    string plug;
};
st info [maxn];
int bfs(int beg, int _end)
{
    queue<int>qu;
    qu.push(beg);
    memset(dft, -1, sizeof(dft));
    dft[beg] = 0;
    while (!qu.empty())
    {
        int temp = qu.front();
        qu.pop();
        int i;
        for (i = head[temp]; i != -1; i = edge[i].next)
        {
            int v = edge[i]._end;
            if (dft[v] >= 0 || edge[i].w <= 0)continue;
            dft[v] = dft[temp] + 1;
            qu.push(v);
        }
    }
    return dft[_end];
}
int dfs(int beg, int _end, int flow)
{
    if (beg == _end)
        return flow;
    int ans = 0;
    int i;
    for (i = head[beg]; i != -1; i = edge[i].next)
    {
        int v = edge[i]._end;
        if (dft[v] != dft[beg] + 1 || edge[i].w <= 0)continue;
        int temp = dfs(v, _end, min(edge[i].w, flow - ans));
        ans += temp;
        edge[i].w -= temp;
        edge[i ^ 1].w += temp;
    }
    return ans;
}
int dinic(int beg, int _end)
{
    int ans = 0;
    while (bfs(beg, _end) != -1)
    {
        ans += dfs(beg, _end, 0x7f7f7f7f);
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
// #ifdef test
//     freopen("/home/time/debug//debug/in", "r", stdin);
//     freopen("/home/time/debug/debug/out", "w", stdout);
// #endif
    int n;
    cin >> n;
    int i;
    map<string , int>ma;
    memset(head, -1, sizeof(head));
    wfor(i, 0, n)
    {
        string s;
        cin >> s;
        if (ma.count(s) == 0)
            ma.insert(make_pair(s, i + 1));
        add(0, ma[s], 1);
        add(ma[s], 0, 0);
    }
    int m;
    cin >> m;
    wfor(i, 0, m)
    {
        cin >> info[i].name >> info[i].plug;
    }
    int k;
    cin >> k;
    wfor(i, 0, k)
    {
        string a, b;
        cin >> a >> b;
        if (ma.count(a) == 0)
            ma.insert(make_pair(a, ma.size() + 1));
        if (ma.count(b) == 0)
            ma.insert(make_pair(b, ma.size() + 1));
        add(ma[b], ma[a], 0x7f7f7f7f);
        add(ma[a], ma[b], 0);
    }
    wfor(i, 0, m)
    {
        if (ma.count(info[i].plug) != 0)
        {
            ma.insert(make_pair(info[i].name, ma.size() + 1));
            add(ma[info[i].plug], ma[info[i].name], 1);
            add(ma[info[i].name], ma[info[i].plug], 0);
            add(ma[info[i].name], 1000, 1);
            add(1000, ma[info[i].name], 0);
        }
    }
    int ans = dinic(0, 1000);
    cout << m - ans << endl;
    return 0;
}
