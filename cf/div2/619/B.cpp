#include <iostream>
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
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll i;
        ll last;
        ll now;
        cin>>now;
        last=now;
        ll minnum=1e9+5;
        ll maxnum=-10;
        ll m=-100;
        wfor(i,1,n)
        {
            cin>>now;
            if(last==-1&&now!=-1)
            {
                minnum=min(minnum,now);
                maxnum=max(maxnum,now);
            }else if(last!=-1&&now==-1)
            {
                minnum=min(minnum,last);
                maxnum=max(maxnum,last);
            }else 
            {
                m=max(m,abs(now-last));
            }
            last=now;
        }
        ll k=(minnum+maxnum)/2;
        if(minnum==1e9+5&&maxnum==-10)
        {
            k=0;
            minnum=maxnum=0;
        }
        m=max(m,max(abs(minnum-k),abs(maxnum-k)));
        cout<<m<<" "<<k<<endl;
    }
    return 0;
}
