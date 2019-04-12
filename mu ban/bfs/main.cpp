#include <iostream>
#include<queue>
using namespace std;
int m,n;
char ma[45][45];
int ans[45][45];
void bfs(int x,int y);
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin>>ma[i][j];
    bfs(0,0);
    cout<<ans[n-1][m-1]<<endl;
    return 0;
}
void bfs(int x,int y)
{
    queue<int>qu;
    qu.push(x);
    qu.push(y);
    ans[x][y]=1;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
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
            if(x1>=0&&y1>=0&&x1<n&&y1<m&&ans[x1][y1]==0&&ma[x1][y1]!='#')
            {
                ans[x1][y1]=ans[x][y]+1;
                qu.push(x1);
                qu.push(y1);
            }
        }
    }
}
