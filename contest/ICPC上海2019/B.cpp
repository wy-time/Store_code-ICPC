#include <iostream>
#include <set>
#include <map>
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
    int t;
    cin >> t;
    int casecnt = 0;
    while (t--)
    {
        casecnt++;
        cout << "Case #" << casecnt << ": ";
        map<int, int>vis;
        int n, m;
        cin >> n >> m;
        int i;
        wfor(i, 0, m)
        {
            int l, r;
            cin >> l >> r;
            if (vis.count(l) == 0)
                vis.insert(make_pair(l, 1));
            else
                vis[l]++;
            if (vis.count(r + 1) == 0)
                vis.insert(make_pair(r + 1, -1));
            else
                vis[r + 1]--;
        }
        pair<int, int>last = *vis.begin();
        int ans = 0;
        int pre = 0;
        vis.erase(vis.begin());
        for (auto k : vis)
        {
            if (k.second == 0)
                continue;
            if (last.second > 0 && k.second > 0)
            {
                pre += last.second;
                if (pre % 2 != 0)
                    ans += k.first - last.first;
            } else if (last.second > 0 && k.second < 0)
            {
                pre += last.second;
                if (pre % 2 != 0)
                    ans += k.first - last.first;
            } else if (last.second < 0 && k.second < 0)
            {
                pre += last.second;
                if (pre % 2 != 0)
                    ans += k.first - last.first;
            } else
            {
                pre += last.second;
                if (pre % 2 != 0)
                    ans += k.first - last.first;
            }
            last = k;
        }
        cout << ans << endl;
    }
    return 0;
}
