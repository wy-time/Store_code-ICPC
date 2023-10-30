#include <iostream>
#include <cstring> 
#include <set> 
#include <vector> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn=1e5+3;
vector<vector<int>>G(maxn);
int vis[maxn];
vector<int>ans;
set <pair<int,int>>edge;
int flag=0;
int slove2(int root,int need,int f)
{
    vis[root]=1;
    if(ans.size()>=need)
        return 1;
    if(f)
    {
        ans.push_back(root);
    }
    for(auto v:G[root])
    {
        if(vis[v])continue;
        int ret=slove2(v,need,f^1);
        if(ret)
            return 1;
    }
    return 0;
}
int slove(int now,int pre)
{
    vis[now]=1;
    for(auto v:G[now])
    {
        if(flag==1)
            return -1;
        int ret=0;
        if(vis[v]==0)
            ret=slove(v,now);
        if(ret==-1)
            continue;
        if(flag==1)
            return -1;
        if((vis[v]!=0&&v!=pre)||ret==1)
        {
            if(ans.empty())
            {
                ans.push_back(v);
                ans.push_back(now);
            }
            else
            {
                ans.push_back(now);
                if(now==ans[0])
                {
                    ans.pop_back();
                    flag=1;
                }
            }
            return 1;
        }
    }
    return -1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    int n,m,k;
    cin>>n>>m>>k;
    int i;
    wfor(i,0,m)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        edge.insert(make_pair(u,v));
        edge.insert(make_pair(v,u));
    }
    flag=0;
    slove(1,0);
    if(!ans.empty())
    {
        int len=ans.size();
        int last=ans[0];
        for(int i=2;i<len;i+=2)
        {
            if(edge.count(make_pair(last,ans[i]))!=0)
            {
                int temp=ans[i-1];
                int temp2=ans[i];
                ans.clear();
                ans.push_back(last);
                ans.push_back(temp);
                ans.push_back(temp2);
                break;
            }
            last=ans[i];
        }
    }
    if(!ans.empty()&&ans.size()<=k)
    {
        cout<<2<<endl;
        cout<<ans.size()<<endl;
        for(auto v:ans)
        {
            cout<<v<<" ";
        }
    }else if(ans.empty())
    {
        cout<<1<<endl;
        int need=k/2+(k%2==0?0:1);
        memset(vis,0,sizeof(vis));
        slove2(1,need,1);
        if(ans.size()<need)
        {
            memset(vis,0,sizeof(vis));
            ans.clear();
            slove2(G[1][0],need,1);
        }
        for(auto v:ans)
        {
            cout<<v<<" ";
        }
    }else
    {
        cout<<1<<endl;
        int need=k/2+(k%2==0?0:1);
        int j=0;
        wfor(i,0,need)
        {
            cout<<ans[j]<<" ";
            j+=2;
        }
    }
    return 0;
}
