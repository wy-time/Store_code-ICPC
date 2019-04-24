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
const int maxn = 1e5 + 5;
struct st
{
    int end;
    int next;
};
st edge[maxn * 2];
int head[maxn];
int cnt;
int deg[maxn];
int vis[maxn];
void add(int beg, int end)
{
    edge[++cnt].next = head[beg];
    edge[cnt].end = end;
    head[beg] = cnt;
}
int ans;
vector<int>v;
int slove(int beg, int step, int sum)
{
    int i;
    int sta;
    if (step != 0)
    {
        vector<int>po;
        for (i = head[beg]; i; i = edge[i].next)
        {
            int v = edge[i].end;
            if (!vis[v])
            {
                if (deg[v] == 1)
                {
                    vis[v] = 1;
                    sum++;
                } else
                {
                    po.push_back(v);
                }
            }
        }
        if (sum % 2 != 0)
        {
            for (auto it : po)
            {
                vis[it] = 1;
                sta = slove(it, step + 1, sum);
                if (sta == 1)
                {
                    ans += po.size() - 1;
                    for (auto it2 : po)
                    {
                        if (deg[it2] == 1 && it2 != it)
                        {
                            v.push_back(it2);
                        }
                    }
                    return 1;
                }
                vis[it] = 0;
            }
        } else
        {
            ans += po.size();
            for (auto it : po)
            {
                deg[it]--;
                if (deg[it] == 1)
                {
                    v.push_back(it);
                }
            }
            return 1;
        }
    } else
    {
        for (i = head[beg]; i; i = edge[i].next)
        {
            int v = edge[i].end;
            vis[v] = 1;
            slove(v, step + 1, 2);
        }
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
    wfor(i, 1, n)
    {
        int u, k;
        cin >> u >> k;
        add(u, k);
        add(k, u);
        deg[u]++;
        deg[k]++;
    }
    if (n % 2 != 0)
    {
        cout << -1 << endl;
    } else
    {
        wfor(i, 1, n + 1)
        {
            if (deg[i] == 1)
                v.push_back(i);
        }
        int len = v.size();
        wfor(i, 0, len)
        {
            int it = v[i];
            if (!vis[it])
            {
                vis[it] = 1;
                slove(it, 0, 0);
            }
            len = v.size();
        }
        cout << ans << endl;
    }
    return 0;
}
