#include <iostream>
#include<cstdio>
using namespace std;
void dfs(int x,int y);
char s[105][105];
int n,m;
int main()
{
    cin>>n>>m;
    int cnt=0;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>s[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(s[i][j]=='W')
            {
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;;
    return 0;
}
void dfs(int x,int y)
{
    s[x][y]='.';
    int dx,dy;
    for(dx=-1;dx<=1;dx++)
    {
        for(dy=-1;dy<=1;dy++)
        {
            if(x+dx>=0&&x+dx<n&&y+dy>=0&&y+dy<m&&s[x+dx][y+dy]=='W')
                dfs(x+dx,y+dy);
        }
    }
}
