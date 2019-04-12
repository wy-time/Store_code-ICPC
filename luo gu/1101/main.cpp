#include <iostream>
#include<cstdio>
using namespace std;
char s[105][105];
bool p[105][105];
char flag[8]="yizhong";
int n;
bool dfs(int x,int y,int times,int xx,int yy);
int main()
{
    //freopen("F:\\Desktop\\question\\1.txt","r",stdin);
    cin>>n;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>s[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(s[i][j]=='y')
            {
                if(dfs(i,j,1,0,0))
                {
                    p[i][j]=true;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(!p[i][j])
            {
                cout<<"*";
            }else
            {
                cout<<s[i][j];
            }
        }
        cout<<endl;
    }
    return 0;
}
bool dfs(int x,int y,int times,int xx,int yy)
{
    bool qqq=false;
    if(times==1)
    {
        int dx[3]={-1,1,0};
        int dy[3]={-1,1,0};
        int i,j;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                int x1,y1;
                x1=x+dx[i];
                y1=y+dy[j];
                if(x1>=0&&x1<n&&y1>=0&&y1<n&&s[x1][y1]==flag[times])
                {
                    if(dfs(x1,y1,times+1,dx[i],dy[j]))
                    {
                        p[x1][y1]=true;
                        qqq=true;
                    }
                }
            }
        }
    }else if(times<6)
    {
        int x1,y1;
        x1=x+xx;
        y1=y+yy;
        if(x1>=0&&x1<n&&y1>=0&&y1<n&&s[x1][y1]==flag[times])
        {
            if(dfs(x1,y1,times+1,xx,yy))
            {
                p[x1][y1]=true;
                qqq=true;
            }
        }
    }else
    {
        int x1,y1;
        x1=x+xx;
        y1=y+yy;
        if(x1>=0&&x1<n&&y1>=0&&y1<n&&s[x1][y1]==flag[times])
        {
            p[x1][y1]=true;
            qqq=true;
        }
    }
    return qqq;
}
