#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 3e5 + 5;
const int INF = 1e9;
int op[maxn];
vector<int>G[maxn];
int dfs(int aim, int beg, int &have)
{
    int len = G[beg].size();
    int i;
    if (len == 0)
    {
        if (have > 0)
        {
            have--;
            return INF;
        } else
            return -1;
    }
    if (op[beg] == 1)
    {
        wfor(i, 0, len)
        {
            int v = G[beg][i];
            int temp = have;
            int t = dfs(aim, v, have);
            if (t >= aim)
                return t;
            have = temp;
        }
        return -1;
    } else
    {
        int maxnum = 0;
        wfor(i, 0, len)
        {
            int v = G[beg][i];
            int t = dfs(aim, v, have);
            maxnum = max(maxnum, t);
            if (t < aim)
                return -1;
        }
        return maxnum;
    }
}
int check(int val, int cnt)
{
    int have = cnt - val + 1;
    if (dfs(val, 1, have) != -1)
        return 1;
    else
        return -1;
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
    wfor(i, 1, n + 1)
    {
        cin >> op[i];
    }
    int cnt = n;
    wfor(i, 2, n + 1)
    {
        int t;
        cin >> t;
        if (G[t].size() == 0)
            cnt--;
        G[t].push_back(i);
    }
    int l = 0, r = cnt;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid, cnt) == 1)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << r << endl;
    return 0;
}
