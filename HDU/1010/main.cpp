#include <iostream>
#include<cmath>
using namespace std;
char ma[10][10];
bool flag[10][10];
void dfs(int begx,int begy,int step);
int n,m,t;
bool flag1;
int endx,endy;
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n>>m>>t)
    {
        flag1=false;
        int i,j;
        for(i=0;i<10;i++)
            for(j=0;j<10;j++)
            {
                flag[i][j]=false;
            }
        if(n==0&&m==0&&t==0)
        {
            break;
        }
        int begx,begy;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                cin>>ma[i][j];
            }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                if(ma[i][j]=='S')
                {
                    begx=i;
                    begy=j;
                }
                if(ma[i][j]=='D')
                {
                    endx=i;
                    endy=j;
                }
            }
        /*if(t%2!=(int)(abs(begx-endx)+abs(begy-endy))%2)
        {
            cout<<"NO"<<endl;
            continue;
        }*/
        /*if(t<(int)(abs(begx-endx)+abs(begy-endy)))
        {
            cout<<"NO"<<endl;
            continue;
        }*/
        //flag[begx][begy]=true;
        dfs(begx,begy,0);
        if(flag1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
void dfs(int begx,int begy,int step)
{
    if((t-step)%2!=(int)(abs(begx-endx)+abs(begy-endy))%2)
    {
        return;
    }
    if(t-step<(int)(abs(begx-endx)+abs(begy-endy)))
    {
        return;
    }
    if(ma[begx][begy]=='D'&&step==t)
    {
        flag1=true;
    }
    if(flag1)
        return;
    flag[begx][begy]=true;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int i;
    for(i=0;i<4;i++)
    {
        int x=begx+dx[i];
        int y=begy+dy[i];
        if(x>=0&&x<n&&y>=0&&y<m&&!flag[x][y]&&ma[x][y]!='X')
        {
            //flag[x][y]=true;
            dfs(x,y,step+1);
            flag[x][y]=false;
        }
    }
    return;
}
