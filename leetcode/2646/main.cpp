#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <unordered_map>
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
struct Edge {
    int now;
    vector<int> next;
};
Edge edgeList[55];
bool nodeVisit[55];
int edge[55][55];
int nodeCount[55];
int dp[51][2];
bool dfs(int now,int aim) {
    nodeVisit[now] = true;
    if (now == aim) {
        nodeCount[now]++;
        return true;
    }
    int size = edgeList[now].next.size();
    for(int i=0;i<size;i++) {
        if(nodeVisit[edgeList[now].next[i]]) {
            continue;
        }
        if (dfs(edgeList[now].next[i],aim)){
            nodeCount[now]++;
            return true;
        }
    }
    return false;
}
void treeDp(int now, vector<int> & price) {
    nodeVisit[now] = true;
    int size = edgeList[now].next.size();
    dp[now][0] = 0;
    dp[now][1] = 0;
    for(int i=0;i<size;i++) {
        int next = edgeList[now].next[i];
        if(nodeVisit[next]) {
            continue;
        }
        treeDp(next,price);
        dp[now][0] += min(dp[next][1],dp[next][0]);
        dp[now][1] += dp[next][0];
    }
    dp[now][0] += price[now] * nodeCount[now];
    dp[now][1] += price[now] / 2 * nodeCount[now];
}
int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
    int size = edges.size();
    memset(edge,0,sizeof(int)*55*55);
    memset(nodeCount,0,sizeof(int)*55);
    memset(dp,0xf7,sizeof(int)*51 * 2);
    for(int i=0;i<size;i++) {
        edge[edges[i][0]][edge[i][1]] = 1;
        edge[edges[i][1]][edge[i][0]] = 1;
    }
    edgeList[0].next.clear();
    for(int i=0;i<size;i++) {
        edgeList[edges[i][0]].next.clear();
        edgeList[edges[i][1]].next.clear();
    }
    for(int i=0;i<size;i++) {
        edgeList[edges[i][0]].now = edges[i][0];
        edgeList[edges[i][0]].next.push_back(edges[i][1]);
        edgeList[edges[i][1]].now = edges[i][1];
        edgeList[edges[i][1]].next.push_back(edges[i][0]);
    }
    size = trips.size();
    for(int i=0;i<size;i++) {
        memset(nodeVisit,0,sizeof(bool)*55);
        dfs(trips[i][0],trips[i][1]);
    }
    memset(nodeVisit,0,sizeof(bool)*55);
    treeDp(0,price);
    return min(dp[0][0],dp[0][1]);
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
    // vector<vector<int>>inputEdges = {{0,1},{1,2},{1,3}};
    vector<vector<int>>inputEdges = {{0,1}};
    // vector<vector<int>>trips = {{0,3},{2,1},{2,3}};
    vector<vector<int>>trips = {{0,1},{0,0},{0,0}};
    vector<int> price = {2,4};
    // wfor(i,0,n * m) {
    //     vector<int>temp;
    //     wfor(j,0,m) {
    //         int val;
    //         cin>>val;
    //         temp.push_back(val);
    //     }
    //     cost.push_back(temp);
    // }
    cout<<minimumTotalPrice(4,inputEdges,price,trips)<<endl;
    return 0;
}
