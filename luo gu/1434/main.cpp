#include <iostream>
#include<queue>
#include<cstring>
using namespace std;
int ma[105][105];
bool go[105][105];
//int dfs(int begx,int begy);
int ans[105][105];
int n,m;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    int i,j;
    memset(ans,0,sizeof(ans));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>ma[i][j];
        }
    }
    int r=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(ans[i][j]==0)
            {
                go[i][j]=true;
                r=max(dfs(i,j),r);
                memset(go,false,sizeof(go));
            }
        }
    }
    cout<<r+1;
    return 0;
}
int dfs(int begx,int begy)
{
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int i;
    if(ans[begx][begy]!=0)
        return ans[begx][begy];
    else
    {
        for(i=0;i<4;i++)
        {
            int x=begx+dx[i];
            int y=begy+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&!go[x][y]&&ma[x][y]<ma[begx][begy])
            {
                ans[begx][begy]=max(ans[begx][begy],dfs(x,y)+1);
            }
        }
    }
    return ans[begx][begy];
}
