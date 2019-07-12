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
const int maxn=2e5+5;
const int N=3e6+5;
int num[maxn*2];
int prime[N];
int isprime[N];
int pos[N];
int vis[N];
vector<int>ans;
void getprime()
{
    int i;
    wfor(i,2,N)
    {
        if(prime[i]==0)
        {
            prime[++prime[0]]=i;
            pos[i]=prime[0];
            isprime[i]=1;
        }
        int j;
        for(j=1;j<=prime[0]&&prime[j]*i<N;++j)
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
    int i;
    wfor(i,0,2*n)
    {
        cin>>num[i];
        vis[num[i]]++;
    }
    sort(num,num+2*n,greater<int>());
    getprime();
    wfor(i,0,2*n)
    {
        if(ans.size()==n)
            break;
        if(vis[num[i]]>0)
        {
            if(isprime[num[i]])
            {
                vis[pos[num[i]]]--;
                ans.push_back(pos[num[i]]);
                vis[num[i]]--;
            }else
            {
                ll j;
                for(j=2;j*j<=num[i];++j)
                {
                    if(num[i]%j==0)
                        break;
                }
                int maxnum=max(j,num[i]/j);
                vis[maxnum]--;
                ans.push_back(num[i]);
                vis[num[i]]--;
            }
        }
    }
    for(auto k:ans)
        cout<<k<<" ";
    cout<<endl;
    return 0;
}
