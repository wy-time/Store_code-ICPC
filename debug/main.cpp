#include <iostream>
#include <algorithm> 
#include <cmath> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
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
    ll t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        ll one=l-1;
        ll beg=0;
        if(one%192==0)
        {
            beg=one/192;
            one=1+one;
        }else
        {
            beg=one/192+1;
            one=(one/192+1)*192;
            one++;
        }
        ll last=r-1;
        ll end=0;
        if(last%192==0)
        {
            end=last/192;
            last+=1;
        }else
        {
            end=last/192;
            last=last/192*192;
            last++;
        }
        ll len=end-beg+1;
        ll sum=len*one+(len)*(len-1)*96;
        cout<<sum<<endl;
    }
    return 0;
}
