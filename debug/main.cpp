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
    int n,m;
    cin>>n>>m;
    int ans=0;
    if(n==m)
    {
        cout<<0<<endl;
        return 0;
    }
    n-=m;
    if(m==0)
        ans=1;
    int bian=n;
    if(m>2&&bian>2)
    {
        m-=2;
        bian-=2;
        ans+=2;
    }
    while(m&&bian)
    {
        m--;
        ans++;
        bian--;
    }
    cout<<ans<<endl;
    return 0;
}
