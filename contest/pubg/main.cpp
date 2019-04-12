#include <iostream>
#include<queue>
#include<cstring>
using namespace std;
int ma[105][105];
int vis[105][105];
const int INF=0x7f7f7f;
typedef struct
{
    int x;
    int y;
    int dis;
}st;
int bfs(int x,int y,int val,int endx,int endy);
int n;
struct rule
{
    bool operator()(const st &a,const st &b)
    {
        return a.dis>b.dis;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n)
    {
        int i,j,r;
        r=0;
        int begx,begy,endx,endy;
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>ma[i][j];
                if(ma[i][j]==-1)
                {
                    begx=i;
                    begy=j;
                }else if(ma[i][j]==-2)
                {
                    endx=i;
                    endy=j;
                }
            }
        }
        r=bfs(begx,begy,0,endx,endy);
        if(r<0)
            r=0;
        cout<<r<<endl;
    }
    return 0;
}
int bfs(int x,int y,int val,int endx,int endy)
{
    priority_queue<st,vector<st>,rule>qu;
    st point;
    point.x=x;
    point.y=y;
    point.dis=val;
    qu.push(point);
    vis[x][y]=1;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    while(!qu.empty())
    {
        point=qu.top();
        qu.pop();
        x=point.x;
        y=point.y;
        val=point.dis;
        for(int i=0;i<4;i++)
        {
            int x1=dx[i]+x;
            int y1=dy[i]+y;
            if(x1==endx&&y1==endy)
                return val;
            if(x1>=0&&x1<n&&y1>=0&&y1<n&&!vis[x1][y1])
            {
                vis[x1][y1]=1;
                point.x=x1;
                point.y=y1;
                point.dis=val+ma[x1][y1];
                qu.push(point);
            }
        }
    }
    return -1;
}
