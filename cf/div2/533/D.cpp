#include <iostream>
#include <queue>
#include <cctype>
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
const int maxn = 1005;
char ma[maxn][maxn];
int vis[maxn][maxn];
int ans[10];
struct st
{
    pair<int, int> postion;
    int id;
    st()
    {
    }
    st(pair<int, int>pa, int b)
    {
        id = b;
        postion.first = pa.first;
        postion.second = pa.second;
    }
};
queue<st>qu;
int n, m, p;
int speed[10];
void bfs()
{
    while (!qu.empty())
    {
        auto temp = qu.front();
        qu.pop();
        int dx[4] = {0, 1, -1, 0};
        int dy[4] = {1, 0, 0, -1};
        int i;
        int j;
        int id = temp.id;
        queue<st>qu2;
        qu2.push(temp);
        wfor(j, 0, speed[id])
        {
            int sz = qu2.size();
            int k;
            wfor(k, 0, sz)
            {
                auto now = qu2.front();
                qu2.pop();
                wfor(i, 0, 4)
                {
                    int x = now.postion.first + dx[i];
                    int y = now.postion.second + dy[i];
                    if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && ma[x][y] != '#')
                    {
                        vis[x][y] = now.id;
                        ans[now.id]++;
                        qu2.push(st(make_pair(x, y), now.id));
                    }
                }
            }
            if (qu2.empty())
                break;
        }
        while (!qu2.empty())
        {
            qu.push(qu2.front());
            qu2.pop();
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
// #ifdef test
//     freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// #ifdef ubuntu
//     freopen("/home/time/debug/debug/in", "r", stdin);
//     freopen("/home/time/debug/debug/out", "w", stdout);
// #endif
    cin >> n >> m >> p;
    int i, j;
    vector<pair<int, int>>pos[10];
    wfor(i, 1, p + 1)
    {
        cin >> speed[i];
    }
    wfor(i, 0, n)
    {
        wfor(j, 0, m)
        {
            cin >> ma[i][j];
            if (isdigit(ma[i][j]))
            {
                vis[i][j] = ma[i][j] - '0';
                ans[vis[i][j]]++;
                pos[vis[i][j]].push_back(make_pair(i, j));
            }
        }
    }
    wfor(i, 1, p + 1)
    {
        int sz = pos[i].size();
        wfor(j, 0, sz)
        qu.push(st(pos[i][j], i));
    }
    bfs();
    wfor(i, 1, p + 1)
    {
        cout << ans[i] << " ";
    }
    return 0;
}