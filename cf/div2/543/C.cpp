#include <iostream>
#include <cmath>
#include <algorithm>
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
const int INF = 0x7f7f7f7f;
const int maxn = 1005;
int num[maxn];
int run[maxn];
int origin[maxn];
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
    int n, k;
    cin >> n >> k;
    int i;
    wfor(i, 0, n)
    {
        cin >> num[i];
    }
    int cnt = 0;
    int now = 0;
    int ruing = 0;
    wfor(i, 0, min(k, n))
    {
        origin[i] = num[cnt];
        run[i] = num[cnt++];
        ruing++;
    }
    k = ruing;
    int over = 0;
    int ans = 0;
    while (ruing)
    {
        int pos = min_element(run, run + k) - run;
        int change = run[pos];
        over++;
        ruing--;
        now = floor(100.0 * over / n + 0.5);
        if (cnt < n)
        {
            origin[pos] = num[cnt];
            run[pos] = num[cnt++];
            ruing++;
            vis[pos] = 0;
        } else
        {
            origin[pos] = INF;
            run[pos] = INF;
        }
        wfor(i, 0, k)
        {
            if (run[i] != INF && i != pos)
                run[i] -= change;
        }
        int minnum = *min_element(run, run + k);
        wfor(i, 0, k)
        {
            if (run[i] != INF)
            {
                int testpos = origin[i] - run[i];
                if (testpos + 1 <= now && origin[i] >= now && now - testpos - 1 < minnum)
                {
                    if (!vis[i])
                    {
                        vis[i] = 1;
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
