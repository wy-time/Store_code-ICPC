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
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
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
        int n;
        cin>>n;
        int ans=0;
        int maxnum=sqrt(n)+1;
        int i;
        wfor(i,2,maxnum)
        {
            if(n%i==0)
                ans=max(ans,max(i,n/i));
        }
        if(ans==0)
            ans=1;
        cout<<ans<<" "<<n-ans<<endl;
    }
    return 0;
}
