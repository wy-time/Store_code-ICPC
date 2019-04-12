#include <iostream>
#include<queue>
#include<cstring>
using namespace std;
int n,m;
char ma[505][505];
int ans[505][505];
void bfs (int x,int y,int mode1);
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    memset(ans,-1,sizeof(ans));
    int i,j;
    int x1,y1,x2,y2,x3,y3;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>ma[i][j];
            if(ma[i][j]=='S')
            {
                x1=i;
                y1=j;
            }
            if(ma[i][j]=='K')
            {
                x2=i;
                y2=j;
            }
            if(ma[i][j]=='E')
            {
                x3=i;
                y3=j;
            }
        }
    }
    bfs(x1,y1,1);
    int sum2=99999999;
    if(ans[x3][y3]!=-1)
    {
        sum2=ans[x3][y3];
    }
    int sum=ans[x2][y2];
    memset(ans,-1,sizeof(ans));
    if(sum==-1&&sum2==99999999)
        cout<<-1;
    else
    {
        bfs(x2,y2,2);
        if(ans[x3][y3]==-1&&sum2==99999999)
            cout<<-1;
        else
        {
            sum+=ans[x3][y3];
            if(ans[x3][y3]!=-1)
                cout<<min(sum,sum2);
            else
                cout<<sum2;
        }
    }
    return 0;
}
void bfs(int x,int y,int mode1)
{
    queue <int> qu;
    ans[x][y]=0;
    qu.push(x);
    qu.push(y);
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    while(!qu.empty())
    {
        x=qu.front();
        qu.pop();
        y=qu.front();
        qu.pop();
        int i;
        for(i=0;i<4;i++)
        {
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1>=0&&x1<n&&y1>=0&&y1<m&&ma[x1][y1]!='W'&&ans[x1][y1]==-1)
            {
                if(mode1==1&&ma[x1][y1]=='D')
                    continue;
                ans[x1][y1]=ans[x][y]+1;
                qu.push(x1);
                qu.push(y1);
            }
        }
    }
}
