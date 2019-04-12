#include <iostream>
using namespace std;
int ma[10][10];
bool blackrow[10];
bool blackline[10];
bool blackdiagplus[20];
bool blackdiag[50];
bool whiterow[10];
bool whiteline[10];
bool whitediagplus[20];
bool whitediag[50];
int dfs(int m,int cnt,bool flag,int ans);
int n;
const int kkk=10;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    int i,j;
    for(i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            cin>>ma[i][j];
        }
    }
    if(n!=0)
        cout<<dfs(n,0,false,0);
    else
        cout<<0;
    return 0;
}
int dfs(int m,int cnt,bool flag,int ans)
{
    if(m==0&&cnt==2*n)
    {
        ans++;
        return ans;
    }
    else if(m==0&&cnt==n)
    {
        m=n;
        flag=true;
    }
    int i=0;
    for (i=0; i<n; i++)
    {
        if(!flag)
        {
            if(ma[n-m][i]&&!blackrow[n-m]&&!blackline[i]&&!blackdiagplus[n-m+i]&&!blackdiag[n-m-i+kkk])
            {
                ma[n-m][i]=0;
                blackrow[n-m]=true;
                blackline[i]=true;
                blackdiagplus[n-m+i]=true;
                blackdiag[n-m-i+kkk]=true;
                ans=dfs(m-1,cnt+1,flag,ans);
                ma[n-m][i]=1;
                blackrow[n-m]=false;
                blackline[i]=false;
                blackdiagplus[n-m+i]=false;
                blackdiag[n-m-i+kkk]=false;
            }
        }else
        {
            if(ma[n-m][i]&&!whiterow[n-m]&&!whiteline[i]&&!whitediagplus[n-m+i]&&!whitediag[n-m-i+kkk])
            {
                ma[n-m][i]=0;
                whiterow[n-m]=true;
                whiteline[i]=true;
                whitediagplus[n-m+i]=true;
                whitediag[n-m-i+kkk]=true;
                ans=dfs(m-1,cnt+1,flag,ans);
                ma[n-m][i]=1;
                whiterow[n-m]=false;
                whiteline[i]=false;
                whitediagplus[n-m+i]=false;
                whitediag[n-m-i+kkk]=false;
            }
        }
    }
    return ans;
}
