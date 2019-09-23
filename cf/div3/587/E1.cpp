#include <iostream>
#include <algorithm> 
#include <vector> 
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
ll sum[maxn];
ll len[maxn];
string ans;
int cnt;
void init()
{
    int base=1;
    int i;
    cnt=1;
    wfor(i,1,maxn)
    {
        int j;
        wfor(j,0,base*9)
        {
            len[cnt]=len[cnt-1]+i;
            sum[cnt]=sum[cnt-1]+len[cnt];
            if(sum[cnt]>1000000000)
                break;
            cnt++;
        }
        if(sum[cnt]>1000000000)
            break;
        base*=10;
    }
    wfor(i,1,cnt+1)
    {
        ans=ans+to_string(i);
    }
}
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
    int q;
    cin>>q;
    init();
    while(q--)
    {
        int k;
        cin>>k;
        int pos=lower_bound(sum+1,sum+1+cnt,k)-sum;
        k-=sum[pos-1];
        cout<<ans[k-1]<<endl;
    }
    return 0;
}
