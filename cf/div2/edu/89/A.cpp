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
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll ans=0;
        ll cha=abs(a-b);
        ans+=min(min(a,b),cha);
        a=b=min(a-cha,b-cha);
        if(a>0)
        {
            ans+=(a/3)*2;
            if(a%3==2)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
