#include <iostream>
#include <cmath> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn=3e5+5;
int num[maxn];
int st[maxn][20];
int st2[maxn][20];
int maxpos[maxn][20];
int minpos[maxn][20];
int two[21];
int ans[maxn];
void init()
{
    int i;
    two[0]=1;
    wfor(i,1,21)
        two[i]=two[i-1]*2;
}
int query_min(int l,int r)
{
    int len=r-l+1;
    len=log2(len);
    if(st2[l][len]<st2[r-two[len]+1][len])
        return minpos[l][len];
    else
        return minpos[r-two[len]+1][len];
}
int query_max(int l,int r)
{
    int len=r-l+1;
    len=log2(len);
    if(st[l][len]>st[r-two[len]+1][len])
    {
        return maxpos[l][len];
    }
    else
    {
        return maxpos[r-two[len]+1][len];
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("/home/time/debug/debug/in","r",stdin);
    freopen("/home/time/debug/debug/out","w",stdout);
    #endif
    init();
    int n;
    cin>>n;
    int i;
    int temp1=0;
    int temp2=1e9;
    wfor(i,0,n)
    {
        cin>>num[i];
        num[i+n]=num[i];
        num[i+2*n]=num[i];
        temp1=max(num[i],temp1);
        temp2=min(num[i],temp2);
    }
    if(temp2*2>=temp1)
    {
        ans[0]=-1;
    }else
    {
        wfor(i,0,3*n)
        {
            st[i][0]=num[i];
            st2[i][0]=num[i];
            minpos[i][0]=i;
            maxpos[i][0]=i;
        }
        int len=log2(n*3);
        int j;
        wfor(j,1,len+2)
        {
            wfor(i,0,3*n)
            {
                if(i+two[j-1]<3*n)
                {
                    st[i][j]=max(st[i][j-1],st[i+two[j-1]][j-1]);
                    if(st[i][j-1]>st[i+two[j-1]][j-1])
                        maxpos[i][j]=maxpos[i][j-1];
                    else
                        maxpos[i][j]=maxpos[i+two[j-1]][j-1];
                    st2[i][j]=min(st2[i][j-1],st2[i+two[j-1]][j-1]);
                    if(st2[i][j-1]<st2[i+two[j-1]][j-1])
                        minpos[i][j]=minpos[i][j-1];
                    else
                        minpos[i][j]=minpos[i+two[j-1]][j-1];
                }
            }
        }
        wfor(i,0,n)
        {
            int l=1,r=2*n;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                int j=i;
                int end=i+mid-1;
                int flag=1;
                while(j<=end)
                {
                    int minpos=query_min(j,end);
                    int maxpos=query_max(j,minpos);
                    int maxnum=num[maxpos];
                    if(num[minpos]*2>=maxnum)
                        j=minpos+1;
                    else
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==0)
                    r=mid-1;
                else
                    l=mid+1;
            }
            ans[i]=r;
            i=query_max(i,i+r-1);
        }
    }
    wfor(i,1,n)
    {
        if(ans[i]==0&&ans[i-1]!=-1)
            ans[i]=ans[i-1]-1;
        else if(ans[i]==0)
            ans[i]=-1;
    }
    wfor(i,0,n)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
