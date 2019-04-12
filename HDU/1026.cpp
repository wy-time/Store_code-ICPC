#include <iostream>
#include <cctype> 
#include <cstring> 
#include <sstream> 
#include <string> 
#include <queue> 
#include <stack> 
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
char ma[105][105];
const int INF=0x7f7f7f7f;
struct st
{
    int pre;
    int x;
    int y;
    st()
    {
        pre=-1;
        x=-1;
        y=-1;
    }
};
st ans[10005];
int dis[10005];
int vis[10005];
int n,m;
void bfs(int begx,int begy,int endx,int endy)
{
    queue<int>qu;
    qu.push(begx);
    qu.push(begy);
    dis[begx*m+begy]=0;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    vis[begx*m+begy]=1;
    ans[begx*m+begy].y=0;
    ans[begx*m+begy].x=0;
    while(!qu.empty())
    {
        int x=qu.front();
        qu.pop();
        int y=qu.front();
        qu.pop();
        vis[x*m+y]=0;
        int i;
        wfor(i,0,4)
        {
            int x1=x+dx[i];
            int y1=y+dy[i];
            int add;
            if(x1>=0&&x1<n&&y1>=0&&y1<m&&ma[x1][y1]!='X')
            {
                if(ma[x][y]=='.')
                    add=1;
                else
                    add=ma[x][y]-'0'+1;
                if(dis[x1*m+y1]>dis[x*m+y]+add)
                {
                    ans[x1*m+y1].pre=x*m+y;
                    ans[x1*m+y1].x=x1;
                    ans[x1*m+y1].y=y1;
                    dis[x1*m+y1]=dis[x*m+y]+add;
                    if(!vis[x1*m+y1])
                    {
                        qu.push(x1);
                        qu.push(y1);
                        vis[x1*m+y1]=1;
                    }
                }
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("/home/time/debug/debug/in","r",stdin);
    freopen("/home/time/debug/debug/out","w",stdout);
    #endif
    while(cin>>n>>m)
    {
        memset(vis,0,sizeof(vis));
        fill(dis,dis+10005,INF);
        int i,j;
        wfor(i,0,n)
        {
            wfor(j,0,m)
            {
                cin>>ma[i][j];
            }
        }
        bfs(0,0,n-1,m-1);
        if(dis[(n-1)*m+m-1]==INF)
        {
            cout<<"God please help our poor hero."<<endl;
            cout<<"FINISH"<<endl;
            continue;
        }
        int t=(n-1)*m+m-1;
        stack<string>res;
        stringstream ssin;
        if(isdigit(ma[n-1][m-1]))
        {
            int cnt=ma[n-1][m-1]-'0';
            ssin<<"FIGHT AT "<<"("<<n-1<<","<<m-1<<")";
            string tt;
            getline(ssin,tt);
            while(cnt--)
            {
                res.push(tt);
            }
        }
        while(ans[t].pre!=-1)
        {
            ssin.clear();
            int temp=ans[t].pre;
            ssin<<"("<<ans[temp].x<<","<<ans[temp].y<<")"<<"->";
            ssin<<"("<<ans[t].x<<","<<ans[t].y<<")";
            string tt;
            ssin>>tt;
            res.push(tt);
            if(dis[temp]+1!=dis[t])
            {
                ssin.clear();
                ssin<<"FIGHT AT "<<"("<<ans[temp].x<<","<<ans[temp].y<<")";
                int cnt=dis[t]-dis[temp];
                string ss;
                getline(ssin,ss);
                while(cnt>1)
                {
                    cnt--;
                    res.push(ss);
                }
            }
            t=temp;
        }
        int cnt=1;
        cout<<"It takes " <<res.size()<<" seconds to reach the target position, let me show you the way."<<endl;
        while(!res.empty())
        {
            string t=res.top();
            res.pop();
            cout<<cnt<<"s:"<<t<<endl;
            cnt++;
        }
        cout<<"FINISH"<<endl;
    }
    return 0;
}
