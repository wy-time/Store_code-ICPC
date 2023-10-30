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
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,m;
        cin>>n>>x>>m;
        int i;
        int nowl=x;
        int nowr=x;
        wfor(i,0,m)
        {
            int l,r;
            cin>>l>>r;
            if((nowl>=l&&nowl<=r)||(nowr>=l&&nowr<=r))
            {
                nowl=min(l,nowl);
                nowr=max(r,nowr);
            }
        }
        cout<<nowr-nowl+1<<endl;
    }
    return 0;
}
