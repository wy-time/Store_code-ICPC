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
const int maxn=2e5+5;
const int INF=0x7f7f7f7f;
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
        int n,k;
        cin>>n>>k;
        int i;
        wfor(i,0,n)
        {
            cin>>num[i];
        }
        sort(num,num+n);
        int ans=INF;
        int res=INF;
        for(i=0;i+k<n;i++)
        {
            int temp=(num[i]+num[i+k])/2;
            int dis=max(temp-num[i],num[i+k]-temp);
            if(dis<res)
            {
                res=dis;
                ans=temp;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
