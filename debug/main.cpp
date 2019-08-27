#include <iostream>
#include <algorithm> 
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
const int maxn=2005;
int num2[maxn];
int num[maxn];
int _next[maxn][maxn];
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
    int n;
    cin>>n;
    int i;
    wfor(i,0,n)
    {
        cin>>num2[i];
        num[i]=num2[i];
    }
    sort(num2,num2+n);
    int p=unique(num2,num2+n)-num2;
    wfor(i,0,n)
    {
        num[i]=lower_bound(num2,num2+p,num[i])-num2;
    }
    int j;
    wfor(i,0,p)
        _next[n-1][i]=-1;
    mfor(i,n-1,0)
    {
        wfor(j,0,p)
        {
            _next[i-1][j]=_next[i][j];
            _next[i-1][num[i]]=i;
        }
    }
    int l=0,r=0;
    int flag=0;
    ll ans=0;
    wfor(i,0,n)
    {
        if(_next[i][num[i]]!=-1)
        {
            if(flag)
            {
                r=i;
            }else
            {
                l=i;
                r=i;
                flag=1;
            }
        }
    }
    ans=r-l+1;
    if(flag==0)
        ans=0;
    l=1e9;r=0;
    flag=0;
    wfor(i,0,n)
    {
        if(i>=l)
            break;
        if(_next[i][num[i]]!=-1)
        {
            l=min(l,_next[i][num[i]]);
            r=max(r,_next[i][num[i]]);
            flag=1;
        }
    }
    wfor(i,l,n)
    {
        if(_next[i][num[i]]!=-1)
            r=max(r,i);
    }
    ans=min(ans,(ll)r-l+1);
    if(!flag)
        ans=0;
    cout<<ans<<endl;
    return 0;
}
