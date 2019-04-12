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
    int t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        //int high=log2(l);
        ll ans=0;
        ll i;
        wfor(i,0,62)
        {
            ll temp=1ll<<i;
            if(temp>r)
                break;
            ans+=temp;
            if(ans>r)
            {
                ans-=temp;
                break;
            }
        }
        if(ans>=l)
            ans=ans|r;
        else
            ans=r;
        cout<<ans<<endl;
    }
    return 0;
}
