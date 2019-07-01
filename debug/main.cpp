#include <iostream>
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
int check(int cnt,int n,int m)
{
    int i;
    int last;
    if(cnt+num[0]>=m)
        last=0;
    else
        last=num[0];
    wfor(i,1,n)
    {
        if(num[i]>last)
        {
            if((num[i]+cnt)>=m&&(num[i]+cnt)%m>=last)
                continue;
            else
                last=num[i];
        }else if(num[i]<last)
        {
            if(num[i]+cnt>=last)
                continue;
            else
            {
                return 0;
            }
        }
    }
    return 1;
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
    int n,m;
    cin>>n>>m;
    int i;
    wfor(i,0,n)
    {
        cin>>num[i];
    }
    int l=0,r=m+5;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid,n,m)==1)
            r=mid-1;
        else
            l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}
