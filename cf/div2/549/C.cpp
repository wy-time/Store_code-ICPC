#include <iostream>
#include <algorithm>
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
const int maxn = 1e5 + 5;
vector<int>G[maxn];
int num[maxn];
int vis[maxn];
int ans[maxn];
int cnt;
int dfs(int beg)
{
    vis[beg] = 1;
    int len = G[beg].size();
    int i;
    if (len == 0)
    {
        if (num[beg] == 1)
        {
            ans[cnt++] = beg;
            return 1;
        }
        return 0;
    }
    int flag = 1;
    wfor(i, 0, len)
    {
        int v = G[beg][i];
        if (!vis[v])
        {
            if (dfs(v) != 1 || num[beg] != 1)
                flag = 0;
        }
    }
    if (flag)
    {
        ans[cnt++] = beg;
    }
    if (num[beg] == 1)
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
    int n;
    cin >> n;
    int i;
    int root = 0;
    wfor(i, 0, n)
    {
        int p, c;
        cin >> p >> c;
        num[i + 1] = c;
        if (p == -1)
            root = i + 1;
        else
            G[p].push_back(i + 1);
    }
    dfs(root);
    if (cnt == 0)
        cout << -1 << endl;
    else
    {
        sort(ans, ans + cnt);
        wfor(i, 0, cnt)
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}
