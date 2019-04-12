#include <iostream>
#include<cstring>
using namespace std;
char ma[10][10];
bool slove (int x,int y,int times,int mode);
bool ans[10][10];
bool h[10];
bool l[10];
int n,k;
int cnt;
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n>>k)
    {
        if(n==-1&&k==-1)
            break;
        memset(ans,false,sizeof(ans));
        memset(h,false,sizeof(h));
        memset(l,false,sizeof(l));
        cnt=0;
        int i,j;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                cin>>ma[i][j];
                if(ma[i][j]=='#')
                    ans[i][j]=true;
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(ans[i][j])
                {
                    if(n==k)
                        slove(i,j,0,1);
                    else
                        slove(i,j,0,0);
                    h[i]=false;
                    l[j]=false;
                }
            }
        }
        //if(k==n)
            cout<<cnt<<endl;
        /*else
        {
            int temp1=1,temp2=1;
            for(i=1;i<=k;i++)
            {
                temp1*=n;
                n-=1;
                temp2*=i;
            }
            int ct=temp1/temp2;
            cout<<cnt*ct<<endl;
        }*/
    }
    return 0;
}
bool slove(int x,int y,int times,int mode)
{
    ans[x][y]=false;
    h[x]=true;
    l[y]=true;
    int i,j;
    int flag=0;
    int ttt=0;
    if(times!=k-1)
    {
        for(i=x+1; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(ans[i][j]&&!h[i]&&!l[j])
                {
                    flag=1;
                    if(!slove(i,j,times+1,mode))
                    {
                        ans[i][j]=true;
                        h[i]=false;
                        l[j]=false;
                        ttt=1;
                        flag=0;
                    }
                }
            }
            if(ttt&&mode)
                break;
        }
        if(!flag)
            return false;
    }
    else
    {
        cnt++;
        return false;
    }
}
