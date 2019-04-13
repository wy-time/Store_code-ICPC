#include <iostream>
#include <cstring> 
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
const int maxn=1e4+5;
int num[maxn];
int sch[maxn];
int _get[maxn];
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
        memset(_get,0,sizeof(_get));
        memset(sch,0,sizeof(sch));
        int n,m,k;
        cin>>n>>m>>k;
        int i;
        int need=n/2;
        wfor(i,1,n+1)
        {
            cin>>num[i];
            sch[num[i]]++;
            if(need>=i)
                _get[num[i]]++;
        }
        int ans=0;
        wfor(i,1,m+1)
        {
            int can=sch[i]/k;
            ans+=min(can,_get[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
