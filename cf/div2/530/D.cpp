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
ll ans;
int vis[maxn];
int pre[maxn];
ll dfs(int beg)
{
    int i;
    int len = G[beg].size();
    ll temp = 2e9;
    wfor(i, 0, len)
    {
        int v = G[beg][i];
        if (!vis[v] && (G[v].size() != 0 || num[v] != -1))
        {
            vis[v] = 1;
            ll t = dfs(v);
            temp = min(t, temp);
        }
    }
    if (num[beg] == -1)
        num[beg] = temp;
    return num[beg];
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
    pre[1] = 1;
    wfor(i, 1, n)
    {
        int t;
        cin >> t;
        G[t].push_back(i + 1);
        pre[i + 1] = t;
    }
    wfor(i, 0, n)
    {
        int t;
        cin >> t;
        num[i + 1] = t;
    }
    dfs(1);
    int flag = 0;
    ans = num[1];
    wfor(i, 1, n + 1)
    {
        if (num[i] != -1)
        {
            if (num[i] >= num[pre[i]])
                ans += num[i] - num[pre[i]];
            else
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag != 1)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
