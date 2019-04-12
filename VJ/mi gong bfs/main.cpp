#include <iostream>
#include<queue>
#include<cstdio>
using namespace std;
char s[45][45];
int bfs();
const int INF=1000000;
typedef pair<int,int>P;
int m,n;
int main()
{
    //freopen("F:\\Desktop\\question\\VJ\\input.txt","r",stdin);
    cin>>m>>n;
    int i;
    for(i=0;i<m;i++)
    {
        cin>>s[i];
    }
    cout<<bfs()+1;
    return 0;
}
int bfs()
{
    int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
    int r[45][45];
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            r[i][j]=INF;
        }
    }
    P p;
    p.first=0,p.second=0;
    queue<P>t;
    t.push(p);
    r[0][0]=0;
    while(t.size())
    {
        int x,y;
        int nx,ny;
        x=nx=t.front().first;
        y=ny=t.front().second;
        t.pop();
        if(x==m-1&&y==n-1)
            break;
        int i;
        for(i=0;i<4;i++)
        {
            nx=x+dx[i];
            ny=y+dy[i];
            if(nx>=0&&nx<m&&ny<n&&ny>=0&&r[nx][ny]==INF&&s[nx][ny]=='.')
            {
                r[nx][ny]=r[x][y]+1;
                t.push(P(nx,ny));
            }
        }
    }
    return r[m-1][n-1];
}
