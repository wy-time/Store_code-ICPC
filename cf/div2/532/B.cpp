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
int num[maxn];
int ans[maxn];
int vis[maxn];
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
    int cnt = 0;
    wfor(i, 0, m)
    {
        int t;
        cin >> t;
        num[t]++;
        if (!vis[t])
        {
            vis[t] = 1;
            cnt++;
        }
        if (cnt == n)
        {
            ans[i] = 1;
            int j;
            wfor(j, 1, n + 1)
            {
                num[j]--;
                if (num[j] == 0)
                {
                    vis[j] = 0;
                    cnt--;
                }
            }
        }
    }
    wfor(i, 0, m)
    {
        cout << ans[i];
    }
    return 0;
}
