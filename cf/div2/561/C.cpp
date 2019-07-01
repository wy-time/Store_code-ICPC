#include <iostream>
#include <cmath> 
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
const int maxn=2e5+5;
int num[maxn];
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
        cin>>num[i];
    }
    sort(num,num+n);
    ll ans=0;
    wfor(i,0,n)
    {
        if(num[i]>0)
        {
            int pos=upper_bound(num,num+n,2*num[i])-num;
            ans+=(pos-1-i);
        }else if(num[i]<0)
        {
            int pos=0;
            if(abs(num[i])%2==0)
                pos=upper_bound(num,num+n,num[i]/2)-num;
            else
                pos=lower_bound(num,num+n,num[i]/2)-num;
            if(pos!=n)
            {
                if(num[pos]>0)
                {
                    pos=lower_bound(num,num+n,0)-num;
                    ans+=(pos-i-1);
                }else
                    ans+=(pos-i-1);
            }else
                ans+=(pos-i-1);
            int mxpos=upper_bound(num,num+n,2*abs(num[i]))-num;
            int mipos=0;
            if(abs(num[i])%2==0)
                mipos=lower_bound(num,num+n,abs(num[i])/2)-num;
            else
                mipos=upper_bound(num,num+n,abs(num[i])/2)-num;
            ans+=mxpos-mipos;
        }
    }
    cout<<ans<<endl;
    return 0;
}
