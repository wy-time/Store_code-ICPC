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
const int maxNum = 1e5+5;
Edge edges[maxNum];
bool nodeVisit[maxNum];
long long dfs(int now, int seats, int &people) {
    int nowPeople = 0;
    long long sum = 0;
    nodeVisit[now] = true;
    if (!edges[now].next.empty()) {
        int len = edges[now].next.size();
        for(int i=0;i<len;i++) {
            if(!nodeVisit[edges[now].next[i]]) {
                int tempPeople = 0;
                sum += dfs(edges[now].next[i],seats,tempPeople);
                nowPeople += tempPeople;
            }
        }
        if(now != 0) {
            nowPeople += 1;
            int nowCar = nowPeople / seats + (nowPeople % seats != 0);
            people = nowPeople;
            return sum + nowCar;
        } else {
            return sum;
        }
    } else {
        if(now != 0) {
            people = 1;
            return 1;
        } else {
            return 0;
        }
        
    }
}
long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    int size = roads.size();
    memset(nodeVisit,0,sizeof(bool) * maxNum);
    edges[0].next.clear();
    for(int i=0;i<size;i++) {
        edges[roads[i][0]].next.clear();
        edges[roads[i][1]].next.clear();
    }
    for(int i=0;i<size;i++) {
        edges[roads[i][0]].now = roads[i][0];
        edges[roads[i][0]].next.push_back(roads[i][1]);
        edges[roads[i][1]].now = roads[i][1];
        edges[roads[i][1]].next.push_back(roads[i][0]);
    }
    int people = 0;
    return dfs(0,seats,people);
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
    vector<vector<int>>cost = {{0,1},{0,2},{1,3},{1,4}};
    // wfor(i,0,n * m) {
    //     vector<int>temp;
    //     wfor(j,0,m) {
    //         int val;
    //         cin>>val;
    //         temp.push_back(val);
    //     }
    //     cost.push_back(temp);
    // }
    int seats = 5;
    cout<<minimumFuelCost(cost,seats)<<endl;
    return 0;
}
