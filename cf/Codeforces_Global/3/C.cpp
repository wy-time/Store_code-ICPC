#include <iostream>
#include <cmath> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(int &x) {
char ch = getchar(); x = 0;
for (; ch < '0' || ch > '9'; ch = getchar());
for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
const int maxn=3e+5;
int num[maxn];
pair<int,int>ans[maxn*5];
int cnt=0;
int slove(int i,int n)
{
    if(2*abs(i-1)>=n&&2*abs(1-num[i])>=n)
    {
        ans[cnt].first=1;
        ans[cnt++].second=i;
        swap(num[i],num[1]);
        if(2*abs(num[1]-1)>=n)
        {
            ans[cnt].first=num[1];
            ans[cnt++].second=1;
            swap(num[1],num[num[1]]);
            return 0;
        }else
            return slove(1,n);
    }else
    {
        ans[cnt].first=n;
        ans[cnt++].second=i;
        swap(num[i],num[n]);
        if(2*abs(n-num[n])>=n)
        {
            ans[cnt].first=num[n];
            ans[cnt++].second=n;
            swap(num[n],num[num[n]]);   
            return i-1;
        }else
            return slove(n,n);
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("/home/time/debug/debug/in","r",stdin);
    freopen("/home/time/debug/debug/out","w",stdout);
    #endif
    int n;
    //cin>>n;
    read(n);
    int i;
    wfor(i,1,n+1)
    {
        //cin>>num[i];
        read(num[i]);
    }
    wfor(i,1,n+1)
    {
        if(num[i]!=i)
        {
            if(2*abs(num[i]-i)>=n)
            {
                ans[cnt].first=i;
                ans[cnt++].second=num[i];
                swap(num[i],num[num[i]]);
                i--;
            }else
            {
                i=slove(i,n);
            }
        }
    }
    printf("%d\n",cnt);
    wfor(i,0,cnt)
    {
        //cout<<ans[i].first<<" "<<ans[i].second<<endl;
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}
