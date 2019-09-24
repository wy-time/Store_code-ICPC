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
vector<int>G[10];
int p[7][7];
int val[10];
int ans;
void init()
{
    int i;
    wfor(i, 1, 7)
    {
        int j;
        wfor(j, i, 7)
        p[i][j] = 1;
    }
}
void dfs(int now, int aim)
{
    if (now == aim + 1)
    {
        init();
        int cnt = 0;
        int i;
        wfor(i, 1, aim + 1)
        {
            for (auto k : G[i])
            {
                if (p[val[i]][val[k]] == 1)
                {
                    cnt++;
                    p[val[i]][val[k]] = 0;
                }
            }
        }
        ans = max(ans, cnt);
    } else
    {
        int i;
        wfor(i, 1, 7)
        {
            val[now] = i;
            dfs(now + 1, aim);
        }
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
    int n, m;
    cin >> n >> m;
    int i;
    wfor(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, n);
    cout << ans << endl;
    return 0;
}
