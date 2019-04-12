#include <iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
char ma[1005][1005];
int flag[1005][1005];
int ans[1000005];
void dfs(int x,int y,int t);
int cnt;
int n;
int main()
{
    //freopen("F:\\Desktop\\question\\luo gu\\1141\\testdata (11).in","r",stdin);
    int m;
    int t =1;
    cin>>n>>m;
    int i;
    getchar();
    getchar();//Âå¹ÈÒªgetcharÁ½´Î
    for(i=0;i<n;i++)
    {
        gets(ma[i]);
    }
    while(m--)
    {
        cnt=0;
        int a,b;
        cin>>a>>b;
        if(flag[a-1][b-1]==0)
        {
            dfs(a-1,b-1,t);
            ans[t]=cnt;
            t++;
        }
        cout<<ans[flag[a-1][b-1]]+1<<endl;
    }
    return 0;
}
void dfs(int x,int y,int t)
{
    flag[x][y]=t;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int i;
    for(i=0;i<4;i++)
    {
        int x1,y1;
        x1=x+dx[i];
        y1=y+dy[i];
        if(x1>=0&&y1>=0&&x1<n&&y1<n&&flag[x1][y1]==false&&ma[x1][y1]!=ma[x][y])
        {
            dfs(x1,y1,t);
            cnt++;
        }
    }
}
