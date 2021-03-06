#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll maxn = 1e5 + 5;
struct EDGE
{
    ll w;
    ll end;
    ll _next;
};
struct node
{
    ll _next[2];
    void init()
    {
        _next[0] = _next[1] = 0;
    }
};
node tree[maxn << 2];
EDGE edge[2 * maxn];
ll head[maxn];
ll cnt;
void add(ll beg, ll end, ll w)
{
    edge[++cnt]._next = head[beg];
    edge[cnt].end = end;
    edge[cnt].w = w;
    head[beg] = cnt;
}
ll num[maxn];
int vis[maxn];
void dfs(ll now, ll res)
{
    ll i;
    vis[now] = 1;
    for (i = head[now]; i; i = edge[i]._next)
    {
        ll v = edge[i].end;
        if (!vis[v])
        {
            res ^= edge[i].w;
            num[v] = res;
            dfs(v, res);
            res ^= edge[i].w;
        }
    }
}
ll tot;
void char_insert(string c)
{
    ll i;
    ll now = 0;
    wfor(i, 0, c.length())
    {
        if (tree[now]._next[c[i] - '0'] == 0)
        {
            tree[++tot].init();
            tree[now]._next[c[i] - '0'] = tot;
        }
        now = tree[now]._next[c[i] - '0'];
    }
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
    ll n;
    cin >> n;
    ll i;
    tot = 0;
    wfor(i, 0, n - 1)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    num[1] = 0;
    dfs(1, 0);
    wfor(i, 1, n + 1)
    {
        bitset<35>bit (num[i]);
        string s = bit.to_string();
        char_insert(s);
    }
    unsigned long long ans = 0;
    wfor(i, 1, n + 1)
    {
        bitset<35>bit (num[i]);
        string s = bit.to_string();
        ll j;
        ll now = 0;
        wfor(j, 0, 35)
        {
            if (tree[now]._next[(s[j] - '0') ^ 1] != 0)
            {
                bit[34 - j] = 1;
                now = tree[now]._next[(s[j] - '0') ^ 1];
            } else
            {
                now = tree[now]._next[(s[j] - '0')];
                bit[34 - j] = 0;
            }
        }
        ans = max(ans, bit.to_ullong());
    }
    cout << ans << endl;
    return 0;
}
