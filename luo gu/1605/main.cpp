#include <iostream>
using namespace std;
bool dfs (int x,int y);
bool ma[6][6]={false};
int ex,ey;
int cnt;
int n,m;
int main()
{
    int t;
    cin>>n>>m>>t;
    int b[2];
    int flag=1;
    cin>>b[0]>>b[1]>>ex>>ey;
    int i;
    ma[ex][ey]=true;
    for(i=0;i<t;i++)
    {
        int a,b;
        cin>>a>>b;
        ma[a][b]=true;
        if(ex==a&&ey==b)
            flag=0;
    }
    if(flag)
        dfs(b[0],b[1]);
    cout<<cnt;
    return 0;
}
bool dfs (int x,int y)
{
    ma[x][y]=true;
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    int i;
    for(i=0;i<4;i++)
    {
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1>=1&&y1>=1&&x1<=n&&y1<=m)
        {
            if(!ma[x1][y1])
            {
                if(!dfs(x1,y1))
                {
                    ma[x1][y1]=false;
                }
            }else if(x1==ex&&y1==ey)
            {
                cnt++;
            }
        }
    }
    return false;
}
