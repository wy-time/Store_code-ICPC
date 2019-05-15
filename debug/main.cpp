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
const int maxn=4e5+5;
int prime[maxn];
void get_prime()
{
    int i;
    wfor(i,2,maxn)
    {
        if(!prime[i])
            prime[++prime[0]]=i;
        int j;
        for(j=1;j<=prime[0]&&i*prime[j]<maxn;j++)
        {
            prime[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
int ans[maxn];
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
    get_prime();
    int n;
    cin>>n;
    int i;
    int cnt[3]={0};
    wfor(i,0,n)
    {
        int t;
        cin>>t;
        cnt[t]++;
    }
    int now=0;
    wfor(i,0,n)
    {
        int pos=lower_bound(prime+1,prime+prime[0]+1,now)-prime;
        if(prime[pos]==now)
            pos++;
        if(cnt[2]!=0&now+2<=prime[pos])
        {
            now+=2;
            cnt[2]--;
            ans[i]=2;
        }else if(cnt[1]!=0&&now+1<=prime[pos])
        {
            now++;
            cnt[1]--;
            ans[i]=1;
        }else
        {
            now+=2;
            cnt[2]--;
            ans[i]=2;
        }
    }
    wfor(i,0,n)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
