#include <iostream>
#include <queue>
#include <cstring>
#include<cstdio>
using namespace std;
void bfs(int x,int y);
int ans[400][400];
int n,m;
int main()
{
    //std::ios::sync_with_stdio(false);
    memset(ans,0xff,sizeof(ans));
    cin>>n>>m;
    int x,y;
    cin>>x>>y;
    bfs(x-1,y-1);
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%-5d",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void bfs(int x,int y)
{
    queue <int> qu;
    qu.push(x);
    qu.push(y);
    ans[x][y]=0;
    int dx[8]={1,1,2,2,-1,-1,-2,-2};
    int dy[8]={-2,2,-1,1,2,-2,1,-1};
    while(!qu.empty())
    {
        x=qu.front();
        qu.pop();
        y=qu.front();
        qu.pop();
        int i;
        for(i=0;i<8;i++)
        {
            int x1,y1;
            x1=x+dx[i];
            y1=y+dy[i];
            if(x1>=0&&y1>=0&&x1<n&&y1<m&&ans[x1][y1]==-1)
            {
                ans[x1][y1]=ans[x][y]+1;
                qu.push(x1);
                qu.push(y1);
            }
        }
    }
}
