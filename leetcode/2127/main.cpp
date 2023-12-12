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

int maximumInvitations(vector<int>& favorite);
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
    int n;
    vector<int> nums;
    int num;
    cin>>n;
    for(int i = 0; i<n;i++)
    {
        cin>>num;
        nums.push_back(num);
    }
    // int k;
    // cin>>k;
    cout<<maximumInvitations(nums)<<endl;
    return 0;
}
const int max_size = 1e5+5;
int dis[max_size];
int in[max_size];
bool vis[max_size];
vector< pair<int,int> > circle;
int max_circle = 0;
void dfs(int step, int n,vector<int>& edges) {
    int next = edges[n];
    dis[n] = step;
    vis[n] = true;
    if (vis[next] && dis[next] == 0) {return;}
    if (dis[next] != 0) {
        if (step - dis[next] == 1) {
            circle.push_back(make_pair(n,next));
        }
        max_circle = max(max_circle,step - dis[next] + 1);
    } else {
        dfs(step+1,next,edges);
    }
}
int maximumInvitations(vector<int>& favorite) {
    memset(in,0,sizeof(int) * max_size);
    memset(vis,0,sizeof(bool) * max_size);
    max_circle = 0;
    circle.clear();
    int size = favorite.size();

    for(int i=0; i<size; i++) {
        if(!vis[i]) {
            memset(dis,0,sizeof(int) * max_size);
            dfs(1,i,favorite);
        }
    }

    queue<int> qu;
    for(int i=0; i<size; i++) {
        in[favorite[i]]++;
    }
    for(int i=0; i<size; i++) {
        if (in[i] == 0) {
            qu.push(i);
        }
    }

    memset(dis,0,sizeof(int) * max_size);
    while (!qu.empty())
    {
        int front = qu.front();
        dis[favorite[front]] = max(dis[favorite[front]], dis[front] + 1);
        qu.pop();
        if(--in[favorite[front]] == 0) {
            qu.push(favorite[front]);
        }
    }
    int res = 0;
    for (auto c = circle.begin(); c != circle.end(); c++) {
        res += dis[(*c).first] + dis[(*c).second] + 2;
    }
    return max(res,max_circle);
}