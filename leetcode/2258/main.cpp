#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int maximumMinutes(vector<vector<int>>& grid);
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\Desktop\question\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    // int n;
    // vector<string> words;
    // cin>>n;
    // string word;
    // for(int i = 0; i<n;i++)
    // {
    //     cin>>word;
    //     words.push_back(word);
    // }
    int n,m;
    cin>>n>>m;
    int i,j;
    vector<vector<int>> edges;
    wfor(i,0,n) {
        vector<int> e;
        wfor(j,0,m){
            int val;
            cin>>val;
            e.push_back(val);
        }
        edges.push_back(e);
    }
    cout<<maximumMinutes(edges)<<endl;
    return 0;
}
int fire[300][300];
int dis[300][300];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
typedef struct myPoint
{
    int x;
    int y;
    int step;
    bool operator<(const myPoint& other) const {
        return step < other.step;
    }
    bool operator>(const myPoint& other) const {
        return step > other.step;
    }
}myPoint;
void bfs(priority_queue<myPoint,vector<myPoint>, greater<myPoint> >& qu,vector<vector<int>>& grid) {
    
    int n = grid.size();
    int m = grid[0].size();
    while (!qu.empty())
    {
        myPoint now = qu.top();
        qu.pop();
        for(int i = 0; i < 4; i++) {
            myPoint next = myPoint{now.x + dx[i],now.y + dy[i],now.step + 1};
            if(next.x >= 0 && next.x < n && next.y >= 0 && next.y < m && grid[next.x][next.y] != 2) {
                if (fire[next.x][next.y] > next.step) {
                    fire[next.x][next.y] = next.step;
                    qu.push(next);
                }
            }
        }
    }
}
int maximumMinutes(vector<vector<int>>& grid) {
    memset(fire, 0x7f, sizeof(int) * 300 * 300);
    memset(dis, -1, sizeof(int) * 300 * 300);
    priority_queue<myPoint,vector<myPoint>, greater<myPoint> > qu;
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if (grid[i][j] == 1) {
                qu.push(myPoint{i,j,0});
                fire[i][j] = 0;
            }
        }
    }
    bfs(qu,grid);
    priority_queue<myPoint,vector<myPoint>, less<myPoint> > res_qu;
    res_qu.push(myPoint{0,0,0});
    while (!res_qu.empty())
    {
        myPoint now = res_qu.top();
        dis[now.x][now.y] = fire[now.x][now.y] - now.step;
        res_qu.pop();
        for(int i = 0; i < 4; i++) {
            myPoint next = myPoint{now.x + dx[i],now.y + dy[i], now.step + 1};
            if(next.x >= 0 && next.x < n && next.y >= 0 && next.y < m && grid[next.x][next.y] != 2 
            && (fire[next.x][next.y] > next.step || (fire[next.x][next.y] == next.step && next.x == n - 1 && next.y == m - 1))) {
                if(dis[next.x][next.y] <= fire[next.x][next.y] - next.step) {
                    int res;
                    if (next.x == n - 1 && next.y == m - 1) {
                        res = fire[next.x][next.y] - next.step + 1;
                    } else {
                        res = fire[next.x][next.y] - next.step;
                        res_qu.push(next);
                    }
                    if (dis[now.x][now.y] == -1) {
                        dis[next.x][next.y] = res;
                    } else {
                        dis[next.x][next.y] = min(dis[now.x][now.y],res);
                    }
                }
            }
        }
    }
    int res = -1;
    if (dis[n-1][m-1] > 1e9) {
        res = 1e9;
    } else if (dis[n-1][m-1] == -1) {
        res = -1;
    } else {
        res = dis[n-1][m-1] - 1;
    }
    return res;
}