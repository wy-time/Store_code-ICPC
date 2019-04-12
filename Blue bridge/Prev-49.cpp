#include <iostream>
#include <set>
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
const int maxn = 100005;
vector<int>G[maxn];
int dfn[maxn];
set<int>ans;
int dfs(int now, int step, int last)
{
    if (dfn[now] == 0)
        dfn[now] = step;
    else
        return 1;
    int sz = G[now].size();
    int i;
    set<int>multi;
    wfor(i, 0, sz)
    {
        int v = G[now][i];
        if (v != last || multi.count(v) != 0)
        {
            int t = dfs(v, step + 1, now);
            if (t == 1)
            {
                if (ans.count(v) == 0)
                {
                    ans.insert(v);
                    return 1;
                }
                else
                    return 2;
            } else if (t == 2)
                return 2;
        } else
            multi.insert(v);
    }
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
    wfor(i, 0, n)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 1, 0);
    set<int>::iterator it;
    for (it = ans.begin(); it != ans.end(); it++)
    {
        cout << *it << " ";
    }
    // cout << *it << endl;
    return 0;
}
