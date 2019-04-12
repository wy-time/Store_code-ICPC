#include <iostream>
using namespace std;
int ma[30][30];
bool result[30][30];
void dfs(int x,int y);
int n;
int main()
{
    cin>>n;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>ma[i][j];
        }
    }
    for(j=0;j<n;j++)
    {
        if(ma[0][j]==0)
        {
            dfs(0,j);
        }
        if(ma[n-1][j]==0)
        {
            dfs(n-1,j);
        }
    }
    for(j=0;j<n;j++)
    {
        if(ma[j][0]==0)
        {
            dfs(j,0);
        }
        if(ma[j][n-1]==0)
        {
            dfs(j,n-1);
        }
    }
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        if(result[i][j]==false&&ma[i][j]!=1)
        {
            ma[i][j]=2;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            cout<<ma[i][j]<<" ";
        }
        cout<<ma[i][j]<<endl;
    }
    return 0;
}
void dfs(int x,int y)
{
    result[x][y]=true;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int i;
    for(i=0;i<4;i++)
    {
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1>=0&&y1>=0&&x1<n&&y1<n&&ma[x1][y1]!=1&&result[x1][y1]==false)
        {
            dfs(x1,y1);
        }
    }
}
