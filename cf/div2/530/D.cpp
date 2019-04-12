#include <iostream>
#include <vector>
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
const int maxn = 2e5 + 5;
ll num[maxn];
vector<int>G[maxn];
int dep[maxn];
ll ans;
int vis[maxn];
int dfs(int beg, ll sum)
{
    int i;
    int len = G[beg].size();
    wfor(i, 0, len)
    {
        int v = G[beg][i];
        ll val = 0;
        if (num[v] == -1)
            val = 0;
        else
        {
            val = num[v] - sum;
            if (val < 0)
            {
                ans = -1;
                return 0;
            }
        }
        if (!vis[v])
        {
            ans += val;
            vis[v] = 1;
            if (dfs(v, max(num[v], num[beg])) == 0)
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
    int n;
    cin >> n;
    int i;
    dep[1] = 1;
    wfor(i, 1, n)
    {
        int t;
        cin >> t;
        G[t].push_back(i + 1);
    }
    wfor(i, 0, n)
    {
        int t;
        cin >> t;
        num[i + 1] = t;
    }
    ans = num[1];
    dfs(1, num[1]);
    cout << ans << endl;
    return 0;
}
