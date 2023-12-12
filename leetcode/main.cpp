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

// void build(TreeNode * root, int i, vector<int> &edge) {
//     root->val = edge[i];
//     if(i*2+1<edge.size() && edge[i*2+1] != -1) {
//         root->left = new TreeNode();
//         build(root->left,i*2+1,edge);
//     }

//     if(i*2+2<edge.size() && edge[i*2+2] != -1) {
//         root->right = new TreeNode();
//         build(root->right,i*2+2,edge);
//     }
// }
struct Node {
    int x;
    int y;
    int cost;
    bool operator > (const Node & other) const {
        return cost > other.cost;
    }
};
int dis[105][105];
int minimumEffortPath(vector<vector<int>>& heights) {
    priority_queue<Node,vector<Node>,greater<Node> >qu;
    memset(dis,0x7f,sizeof(int)*105*105);
    int n = heights.size();
    int m = heights[0].size();
    qu.push(Node{0,0,0});
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    dis[0][0] = 0;
    while (!qu.empty())
    {
        auto now = qu.top();
        qu.pop();
        for(int i=0;i<4;i++){
            int nexty = now.y + dy[i];
            int nextx = now.x + dx[i];
            if(nextx>=0 && nextx < n && nexty >= 0 && nexty < m ){
                int cost = max(now.cost,abs(heights[now.x][now.y] - heights[nextx][nexty]));
                if(cost < dis[nextx][nexty]) {
                    dis[nextx][nexty] = cost;
                    qu.push(Node{nextx,nexty,cost});
                }
            }
        }
    }
    return dis[n-1][m-1];
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
    // int n,m;
    // cin>>n>>m;
    // int i,j;
    // vector<vector<int>>grid;
    // wfor(i,0,n) {
    //     vector<int>temp;
    //     wfor(j,0,m) {
    //         int val;
    //         cin>>val;
    //         temp.push_back(val);
    //     }
    //     grid.push_back(temp);
    // }

    // vector<vector<int>>cost = {{1,5},{5,6},{6,7},{0,1},{1,2},{2,3},{3,4}};
    // vector<vector<int>>inputEdges = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    // vector<vector<int>>inputEdges = {{1,0},{1,2},{3,2},{3,4}};
    vector<vector<int>>inputEdges = {{1,2,2},{3,8,2},{5,3,5}};
    // vector<vector<int>>inputEdges = {{1}};
    // vector<vector<int>>trips = {{0,3},{2,1},{2,3}};
    // wfor(i,0,n * m) {
    //     vector<int>temp;
    //     wfor(j,0,m) {
    //         int val;
    //         cin>>val;
    //         temp.push_back(val);
    //     }
    //     cost.push_back(temp);
    // }
    cout<<minimumEffortPath(inputEdges)<<endl;
    return 0;
}
