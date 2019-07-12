#include <iostream>
#include <algorithm> 
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
const int maxn=105;
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
        wfor(i,0,n)
        {
            cin>>num[i];
            num[i]%=3;
        }
        int ans=0;
        int one=0;
        int two=0;
        wfor(i,0,n)
        {
            if(num[i]==0)
                ans++;
            else if(num[i]==1)
                one++;
            else
                two++;
        }
        if(one>=two)
        {
            ans+=two;
            one-=two;
            two=0;
        }else
        {
            ans+=one;
            two-=one;
            one=0;
        }
        ans+=one/3;
        ans+=two/3;
        cout<<ans<<endl;
    }
    return 0;
}
