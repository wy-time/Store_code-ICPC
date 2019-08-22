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
        int p,b,f;
        cin>>p>>b>>f;
        int h,c;
        cin>>h>>c;
        ll ans=0;
        if(h>c)
        {
            ans+=min(p/2,b)*h;
            p-=min(p/2,b)*2;
            b-=min(p/2,b);
            ans+=min(p/2,f)*c;
        }else
        {
            ans+=min(p/2,f)*c;
            p-=min(p/2,f)*2;
            f-=min(p/2,f);
            ans+=min(p/2,b)*h;
        }
        cout<<ans<<endl;
    }
    return 0;
}
