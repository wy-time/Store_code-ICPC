#include <iostream>
#include <set>
#include <queue>
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
const int maxn = 3e5 + 5;
int num[maxn];
int vis[maxn];
set<pair<int, int>>st;
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
    wfor(i, 0, n)
    {
        cin >> num[i];
    }
    queue<int>can;
    wfor(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        if (v == num[n - 1])
        {
            can.push(u);
            vis[u] = 1;
        }
        st.insert(make_pair(u, v));
    }
    int pos = n - 1;
    int ans = 0;
    while (pos > 0 && !can.empty())
    {
        if (vis[num[pos - 1]] == 1)
        {
            ans++;
            vis[num[pos - 1]] = 0;
            swap(num[pos - 1], num[pos]);
        } else
        {
            int len = can.size();
            wfor(i, 0, len)
            {
                int t = can.front();
                can.pop();
                if (vis[t])
                {
                    if (st.count(make_pair(t, num[pos - 1])) != 0)
                    {
                        can.push(t);
                    } else
                        vis[t] = 0;
                }
            }
        }
        pos--;
    }
    cout << ans << endl;
    return 0;
}
