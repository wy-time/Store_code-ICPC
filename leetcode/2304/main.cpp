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
int dis[51];
typedef struct My_node {
    int n;
    int m;
    int val;
    int dis;
    bool operator < (const My_node& other) const {
        return dis < other.dis;
    }
    bool operator > (const My_node& other) const {
        return dis > other.dis;
    }
}My_node;
int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    memset(dis,0x7f,sizeof(int) *50);
    int line = grid.size();
    int col = moveCost[0].size();
    priority_queue<My_node, vector<My_node>, greater<My_node> > qu;
    for(int i=0;i<col;i++){
        My_node temp = My_node{0,i,grid[0][i],grid[0][i]};
        qu.push(temp);
        dis[grid[0][i]] = grid[0][i];
    } 
    while(!qu.empty())
    {
        My_node now = qu.top();
        qu.pop();
        if(now.n < grid.size() - 1) {
            for(int i=0;i<col;i++) {
                int tempDis = dis[now.val]+moveCost[now.val][i] + grid[now.n+1][i];
                if(tempDis < dis[grid[now.n+1][i]]){
                    dis[grid[now.n+1][i]] = tempDis;
                    qu.push(My_node{now.n+1,i,grid[now.n+1][i],tempDis});
                }
            }
        }
    }
    int ans = 0x7f7f7f7f;
    for(int i=0;i<col;i++) {
        ans = min(dis[grid[line - 1][i]],ans);
    }
    return ans;
}
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
    vector<vector<int>>grid;
    wfor(i,0,n) {
        vector<int>temp;
        wfor(j,0,m) {
            int val;
            cin>>val;
            temp.push_back(val);
        }
        grid.push_back(temp);
    }

    vector<vector<int>>cost;
    wfor(i,0,n * m) {
        vector<int>temp;
        wfor(j,0,m) {
            int val;
            cin>>val;
            temp.push_back(val);
        }
        cost.push_back(temp);
    }
    cout<<minPathCost(grid,cost)<<endl;
    return 0;
}
