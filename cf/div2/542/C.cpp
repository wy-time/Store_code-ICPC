#include <iostream>
#include <string>
#include <cmath>
#include <queue>
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
int n;
int ma[55][55];
int vis[55][55];
vector<pair<int, int>>st1, st2;
const ll INF = 1e18;
void bfs(int begx, int begy, int flag)
{
    if (flag == 1)
        st1.push_back(make_pair(begx, begy));
    else
        st2.push_back(make_pair(begx, begy));
    queue<pair<int, int>>qu;
    qu.push(make_pair(begx, begy));
    vis[begx][begy] = 1;
    while (!qu.empty())
    {
        int x1 = qu.front().first;
        int y1 = qu.front().second;
        qu.pop();
        int dx[4] = {0, 1, -1, 0};
        int dy[4] = {1, 0, 0, -1};
        int i;
        wfor(i, 0, 4)
        {
            int x = x1 + dx[i];
            int y = y1 + dy[i];
            if (x >= 0 && y >= 0 && x < n && y < n && ma[x][y] == 0 && !vis[x][y])
            {
                vis[x][y] = 1;
                qu.push(make_pair(x, y));
                if (flag == 1)
                    st1.push_back(make_pair(x, y));
                else
                    st2.push_back(make_pair(x, y));
            }
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
    cin >> n;
    int i, j;
    int begx, begy, endx, endy;
    cin >> begx >> begy >> endx >> endy;
    wfor(i, 0, n)
    {
        string s;
        cin >> s;
        wfor(j, 0, n)
        {
            ma[i][j] = s[j] - '0';
        }
    }
    bfs(begx - 1, begy - 1, 1);
    bfs(endx - 1, endy - 1, 2);
    int sz1 = st1.size();
    int sz2 = st2.size();
    ll ans = INF;
    wfor(i, 0, sz1)
    {
        wfor(j, 0, sz2)
        {
            ans = min((ll)(st1[i].first - st2[j].first) * (st1[i].first - st2[j].first) + (st1[i].second - st2[j].second) * (st1[i].second - st2[j].second), ans);
        }
    }
    cout << ans << endl;
    return 0;
}
