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
const int maxn=1005;
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
    int n,k;
    cin>>n>>k;
    int i;
    wfor(i,0,n)
    {
        int t;
        cin>>t;
        num[t]++;
    }
    int can=n/2+(n%2!=0);
    sort(num+1,num+k+1,greater<int>());
    int cnt=0;
    int ans=0;
    wfor(i,1,k+1)
    {
        if(cnt+num[i]/2<=can)
        {
            cnt+=num[i]/2;
            ans+=num[i]/2*2;
            num[i]%=2;
        }else
        {
            int cha=can-cnt;
            cnt+=cha;
            ans+=cha*2;
            num[i]-=cha*2;
        }
    }
    if(cnt<can)
    {
        wfor(i,1,k+1)
        {
            if(num[i]!=0&&cnt<can)
            {
                cnt++;
                ans++;
                num[i]=0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
