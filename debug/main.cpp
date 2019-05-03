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
    int n,a,b;
    cin>>n>>b>>a;
    int i;
    wfor(i,0,n)
    {
        cin>>num[i];
    }
    int ans=0;
    int maxa=a;
    wfor(i,0,n)
    {
        if(a==0&&b==0)
            break;
        if(num[i]==1)
        {
            if(b!=0)
            {
                b--;
                a=min(a+1,maxa);
                ans++;
            }else if(a!=0)
            {
                a--;
                ans++;
            }
        }else 
        {
            if(a!=0)
            {
                a--;
                ans++;
            }else if(b!=0)
            {
                b--;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
