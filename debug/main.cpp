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
vector<int>G[1005];
const int maxn=1e6+5;;
int prime[maxn];
int isprime[maxn];
void get_prime()
{
    ll i;
    wfor(i,2,maxn)
    {
        if(prime[i]==0)
        {
            prime[++prime[0]]=i;
            isprime[i]=1;
        }
        ll j;
        for(j=1;j<=prime[0]&&prime[j]*i<maxn;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)
                break;
        }
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
    int n;
    cin>>n;
    get_prime();
    if(n<=2)
        cout<<-1<<endl;
    else
    {
        int now=0;
        int i;
        wfor(i,1,n)
        {
            G[i].push_back(i+1);
        }
        G[n].push_back(1);
        now=n;
        int flag=1;
        if(!isprime[now])
        {
            int pos=upper_bound(prime+1,prime+prime[0]+1,now)-prime;
            int cha=prime[pos]-now;
            int can=n/2;
            if(can>=cha)
            {
                wfor(i,1,cha+1)
                {
                    G[i].push_back(G[i][0]+1);
                }
                now=prime[pos];
            }else
                flag=0;
        }
        if(flag==1)
        {
            cout<<now<<endl;
            wfor(i,1,n+1)
            {
                for(auto k:G[i])
                    cout<<i<<" "<<k<<endl;
            }
        }else
            cout<<-1<<endl;
    }
    return 0;
}
