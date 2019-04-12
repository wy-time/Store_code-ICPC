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
const int maxn = 5005;
int num[maxn];
int cnt[maxn];
int vis[maxn];
int ans[maxn];
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
    int maxnum = 0;
    wfor(i, 0, n)
    {
        cin >> num[i];
        cnt[num[i]]++;
        maxnum = max(maxnum, cnt[num[i]]);
    }
    if (maxnum > k)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        int i;
        wfor(i, 0, n)
        {
            ans[i] = cnt[num[i]];
            cnt[num[i]]--;
            vis[ans[i]]++;
        }
        if (maxnum == k)
        {
            wfor(i, 0, n)
            {
                cout << ans[i] << " ";
            }
        } else
        {
            int need = k;
            wfor(i, 0, n)
            {
                if (need > maxnum)
                {
                    if (vis[ans[i]] > 1)
                    {
                        vis[ans[i]]--;
                        ans[i] = need;
                        need--;
                    }
                }
                cout << ans[i] << " ";
            }
        }
    }
    return 0;
}
