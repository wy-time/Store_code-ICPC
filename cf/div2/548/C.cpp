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
const ll mod = 1e9 + 7;
struct EDGE
{
    int _end;
    int next;
};
EDGE edge [2 * maxn];
int head[maxn];
int cnt;
void add(int u, int v)
{
    edge[++cnt].next = head[u];
    edge[cnt]._end = v;
    head[u] = cnt;
}
int ans[maxn];
int vis[maxn];
int slove(int begx)
{
    int i;
    int num = 0;
    vis[begx] = 1;
    for (i = head[begx]; i; i = edge[i].next)
    {
        int v = edge[i]._end;
        if (!vis[v])
        {
            num += slove(v);
        }
    }
    return num + 1;
}
ll ksm(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
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
    int n, k;
    cin >> n >> k;
    int i;
    wfor(i, 0, n)
    {
        int u, v, t;
        cin >> u >> v >> t;
        if (t == 0)
        {
            add(u, v);
            add(v, u);
        }
    }
    int ccnt = 0;
    wfor(i, 1, n + 1)
    {
        int t;
        if (!vis[i])
        {
            t = slove(i);
            ans[ccnt++] = t;
        }
    }
    ll sum = ksm(n, k);
    ll cannot = 0;
    wfor(i, 0, ccnt)
    {
        cannot = (cannot + ksm(ans[i], k)) % mod;
    }
    cout << (sum - cannot + mod) % mod << endl;
    return 0;
}
