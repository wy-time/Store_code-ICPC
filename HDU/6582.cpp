#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(ll &x) {
    char ch = getchar(); x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
const ll maxn = 2e4 + 5;
const ll INF = 1e18;
struct EDGE
{
    ll next;
    ll end;
    ll w;
};
struct node
{
    ll dis;
    ll id;
    bool operator <(const node& other)const
    {
        return dis > other.dis;
    }
    node() {}
    node(ll a, ll b)
    {
        dis = b;
        id = a;
    }
};
ll head1[maxn];
EDGE edge1[maxn];
EDGE edge2[maxn];
ll head2[maxn];
ll cnt = -1;
void add(ll beg, ll end, ll w)
{
    edge1[++cnt].next = head1[beg];
    edge1[cnt].w = w;
    edge1[cnt].end = end;
    head1[beg] = cnt;
}
ll cnt2 = -1;
void add2(ll beg, ll end, ll w)
{
    edge2[++cnt2].next = head2[beg];
    edge2[cnt2].w = w;
    edge2[cnt2].end = end;
    head2[beg] = cnt2;
}
ll dis[maxn];
void dij(ll beg)
{
    priority_queue<node>qu;
    qu.push(node(beg, 0));
    while (!qu.empty())
    {
        ll now = qu.top().id;
        qu.pop();
        ll i;
        for (i = head1[now]; i != -1; i = edge1[i].next)
        {
            ll v = edge1[i].end;
            if (dis[v] > dis[now] + edge1[i].w)
            {
                dis[v] = dis[now] + edge1[i].w;
                qu.push(node(v, dis[v]));
            }
        }
    }
}
ll dft[maxn];
ll bfs(ll beg, ll _end)
{
    queue<ll>qu;
    qu.push(beg);
    memset(dft, 0, sizeof(dft));
    dft[beg] = 1;
    while (!qu.empty())
    {
        ll temp = qu.front();
        qu.pop();
        for (ll i = head2[temp]; i != -1; i = edge2[i].next)
        {
            ll v = edge2[i].end;
            if (edge2[i].w <= 0 || dft[v])
                continue;
            dft[v] = dft[temp] + 1;
            qu.push(v);
        }
    }
    return dft[_end];
}
ll dfs(ll beg, ll _end, ll flow)
{
    if (beg == _end)
        return flow;
    ll ans = 0;
    for (ll i = head2[beg]; i != -1; i = edge2[i].next)
    {
        ll v = edge2[i].end;
        if (edge2[i].w <= 0) continue;
        if (dft[v] != dft[beg] + 1) continue;
        ll temp = dfs(v, _end, min(edge2[i].w, flow - ans));
        edge2[i].w -= temp;
        edge2[i ^ 1].w += temp;
        ans += temp;
    }
    if (!ans) dft[beg] = -1;
    return ans;
}
ll dinic(ll beg, ll _end)
{
    ll ans = 0;
    while (bfs(beg, _end))
    {
        ans += dfs(beg, _end, INF);
    }
    return ans;
}
int main()
{
    //std::ios::sync_with_stdio(false);
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
    freopen("/home/time/debug/debug/in", "r", stdin);
    freopen("/home/time/debug/debug/out", "w", stdout);
#endif
    ll t;
    //cin>>t;
    read(t);
    while (t--)
    {
        cnt2 = -1;
        cnt = -1;
        memset(head1, -1, sizeof(head1));
        memset(head2, -1, sizeof(head2));
        ll n, m;
        //cin>>n>>m;
        read(n);
        read(m);
        fill(dis, dis + n + 1, INF);
        ll i;
        wfor(i, 0, m)
        {
            ll u, v, w;
            //cin>>u>>v>>w;
            read(u), read(v), read(w);
            add(u, v, w);
        }
        dis[1] = 0;
        dij(1);
        wfor(i, 1, n + 1)
        {
            for (ll j = head1[i]; j != -1; j = edge1[j].next)
            {
                ll v = edge1[j].end;
                if (dis[v] == dis[i] + edge1[j].w)
                {
                    add2(i, v, edge1[j].w);
                    add2(v, i, 0);
                }
            }
        }
        add2(0, 1, INF);
        add2(1, 0, 0);
        add2(n, n + 1, INF);
        add2(n + 1, n, 0);
        ll ans = dinic(0, n + 1);
        //cout<<ans<<endl;
        printf("%lld\n", ans);
    }
    return 0;
}