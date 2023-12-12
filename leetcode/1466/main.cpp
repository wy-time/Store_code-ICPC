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
    vector<pair<int,bool>> next;
};
const int maxNum = 5e4+5;
Edge edgeList[maxNum];
bool nodeVisit[maxNum];
int sumChange = 0;
void dfs(int now) {
    int size = edgeList[now].next.size();
    nodeVisit[now] = true;
    for(int i=0;i<size;i++){
        int next = edgeList[now].next[i].first;
        if(!nodeVisit[next]) {
            if(edgeList[now].next[i].second) {
                sumChange++;
            }
            dfs(next);
        }
    }
}
int minReorder(int n, vector<vector<int>>& connections) {
    sumChange = 0;
    memset(nodeVisit,0,sizeof(bool)*maxNum);
    int size = connections.size();
    edgeList[0].next.clear();
    for(int i=0;i<size;i++) {
        edgeList[connections[i][0]].next.clear();
        edgeList[connections[i][1]].next.clear();
    }
    for(int i=0;i<size;i++) {
        edgeList[connections[i][0]].now = connections[i][0];
        edgeList[connections[i][0]].next.push_back(make_pair(connections[i][1],false));
        edgeList[connections[i][1]].now = connections[i][1];
        edgeList[connections[i][1]].next.push_back(make_pair(connections[i][0],true));
    }
    dfs(0);
    return n-1-sumChange;
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
    vector<vector<int>>inputEdges = {{1,0},{2,0}};
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
    cout<<minReorder(3,inputEdges)<<endl;
    return 0;
}
