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
const int maxn=1e5+5;
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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i;
        wfor(i,1,n+1)
        {
            cin>>num[i];
        }
        int q;
        cin>>q;
        while(q--)
        {
            ll ans=0;
            int l,r;
            cin>>l>>r;
            int len=r-l+1;
            if(len%4==0)
            {
                ans=0;
            }else if(len%4==1)
            {
                ans=num[l];
                for(i=l+4;i<=r;i+=4)
                    ans^=num[i];
            }else if(len%4==2)
            {
                ans=num[l];
                if(len>1)
                    ans^=num[l+1];
                for(i=l+4;i<=r;i+=4)
                {
                    ans^=num[i];
                    if(i+1<=r)
                        ans^=num[i+1];
                }
            }else
            {
                if(len>1)
                {
                    ans=num[l+1];
                    for(i=l+1+4;i<=r;i+=4)
                    {
                        ans^=num[i];
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
