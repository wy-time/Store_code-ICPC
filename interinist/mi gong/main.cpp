/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define random(a,b) ((a)+rand()%((b)-(a)+1))//随机数
const int maxn=300;
int ma[maxn][maxn];
int vis[maxn][maxn];//访问标记
int dfs(int begx,int begy);//找通路的
int n;
int main()
{
    int seed=time(NULL);
    srand(seed);
    //n=random(5,30);//迷宫大小
    n=5;
    printf("目前大小%d*%d\n",n,n);
    printf("**是路，■是墙\n");
    int i,j;
    ma[0][1]=1;
    ma[n+1][n]=1;
    ma[1][1]=1;
    ma[n][n]=1;
    while(1)
    {
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                ma[i][j]=random(0,1);
            }
        }
        for(i=0;i<=n+1;i++)
        {
            for(j=0;j<=n+1;j++)
            {
                printf("%d ",ma[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        if(dfs(0,1))
        {
            break;
        }
    }
    for(i=0;i<=n+1;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(ma[i][j]==1)
                printf("** ");
            else
                printf("■ ");
        }
        if(ma[i][j]==1)
            printf("**\n");
        else
            printf("■\n");
    }
    return 0;
}
int dfs(int begx,int begy)
{
    vis[begx][begy]=1;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int x1,y1;
    if(begx==n&&begy==n)
    {
        return 1;
    }
    for(int i=0;i<4;i++)
    {
        x1=begx+dx[i];
        y1=begy+dy[i];
        if(x1>=0&&x1<=n&&y1>=0&&y1<=n&&!vis[x1][y1]&&ma[x1][y1]==1)
        {
            if(dfs(x1,y1))
                return 1;
        }
    }
    do
    {
        int bk=random(0,3);
        x1=begx+dx[bk];
        y1=begy+dy[bk];
    }while(x1<1&&x1>n&&y1<1&&y1>n);
    ma[x1][y1]=1;
    if(dfs(x1,y1))
        return 1;
    return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<queue>
#define random(a,b) ((a)+rand()%((b)-(a)+1))//随机数
using namespace std;
const int maxn=300;
int ma[maxn][maxn];
int vis[maxn][maxn];//访问标记
int bfs(int begx,int begy);//找通路的
int n;
int main()
{
    int seed=time(NULL);
    srand(seed);
    n=random(5,30);//迷宫大小
    printf("目前大小%d*%d\n",n,n);
    printf("**是路，■是墙\n");
    int i,j;
    ma[0][1]=1;
    ma[n+1][n]=1;
    ma[1][1]=1;
    ma[n][n]=1;
    int cnt=0;
    while(1)
    {
        for(i=0;i<=n+1;i++)
        {
            for(j=0;j<=n+1;j++)
            {
                vis[i][j]=0;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                ma[i][j]=random(0,1);
            }
        }
        /*for(i=0;i<=n+1;i++)
        {
            for(j=0;j<=n+1;j++)
            {
                printf("%d ",ma[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
        cnt++;
        if(cnt%10000==0)
            printf("%d万\n",cnt/10000);
        if(bfs(0,1))
        {
            break;
        }
    }
    for(i=0;i<=n+1;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(ma[i][j]==1)
                printf("** ");
            else
                printf("■ ");
        }
        if(ma[i][j]==1)
            printf("**\n");
        else
            printf("■\n");
    }
    return 0;
}
int bfs(int begx,int begy)
{
    vis[begx][begy]=1;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    queue<int>qu;
    qu.push(begx);
    qu.push(begy);
    while(!qu.empty())
    {
        begx=qu.front();
        qu.pop();
        begy=qu.front();
        qu.pop();
        if(begx==n&&begy==n)
        {
            return 1;
        }
        for(int i=0;i<4;i++)
        {
            int x1=begx+dx[i];
            int y1=begy+dy[i];
            if(x1>=0&&x1<=n&&y1>=0&&y1<=n&&!vis[x1][y1]&&ma[x1][y1]==1)
            {
                qu.push(x1);
                qu.push(y1);
                vis[x1][y1]=1;
            }
        }
    }
    return 0;
}

