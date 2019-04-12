#include <iostream>
#include<queue>
#include<cstdio>
using namespace std;
int level,n,m;
const int INF =100000000;
char ma[35][35][35];
int ans[35][35][35];
typedef struct
{
    int l;
    int x;
    int y;
} st;
void bfs(int l,int x,int y);
int main()
{
    //std::ios::sync_with_stdio(false);
    while(cin>>level>>n>>m)
    {
        if(level==0&&n==0&&m==0)
            break;
        int i,j,k;
        st aim;
        for(i=0; i<level; i++)
        {
            for(j=0; j<n; j++)
            {
                for(k=0; k<m; k++)
                {
                    cin>>ma[i][j][k];
                    ans[i][j][k]=INF;
                    if(ma[i][j][k]=='E')
                    {
                        aim.l=i;
                        aim.x=j;
                        aim.y=k;
                    }
                }
            }
            getchar();
        }
        for(i=0; i<level; i++)
            for(j=0; j<n; j++)
                for(k=0; k<m; k++)
                {
                    if(ma[i][j][k]=='S')
                    {
                        bfs(i,j,k);
                        break;
                    }
                }
        if(ans[aim.l][aim.x][aim.y]!=INF)
            cout<<"Escaped in "<<ans[aim.l][aim.x][aim.y]<<" minute(s)."<<endl;
        else
            cout<<"Trapped!"<<endl;
    }
    return 0;
}
void bfs(int l,int x,int y)
{
    queue<st>que;
    st zuobiao;
    ans[l][x][y]=0;
    zuobiao.l=l,zuobiao.x=x,zuobiao.y=y;
    que.push(zuobiao);
    int dx[6]= {0,-1,0,1,0,0};
    int dy[6]= {1,0,-1,0,0,0};
    int dl[6]= {0,0,0,0,1,-1};
    int i;
    while(ma[zuobiao.l][zuobiao.x][zuobiao.y]!='E'&&!que.empty())
    {
        st temp;
        temp=que.front();
        que.pop();
        l=temp.l,x=temp.x,y=temp.y;
        for(i=0; i<6; i++)
        {
            zuobiao.l=l+dl[i];
            zuobiao.x=x+dx[i];
            zuobiao.y=y+dy[i];
            if(zuobiao.x>=0&&zuobiao.y>=0&&zuobiao.l>=0&&zuobiao.x<n&&zuobiao.y<m&&zuobiao.l<level&&ma[zuobiao.l][zuobiao.x][zuobiao.y]!='#'&&ans[zuobiao.l][zuobiao.x][zuobiao.y]==INF)
            {
                ans[zuobiao.l][zuobiao.x][zuobiao.y]=ans[l][x][y]+1;
                que.push(zuobiao);
            }
        }
    }
}
