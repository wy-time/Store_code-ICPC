#include <iostream>
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
const int maxn=1e6+5;
vector<pair<int,int>>edge;
int prime [maxn];
int isprime[maxn];
void getprime()
{
    ll i;
    wfor(i,2,maxn)
    {
        if(!prime[i])
        {
            prime[++prime[0]]=i;
            isprime[i]=1;
        }
        ll j;
        for(j=1;j<=prime[0]&&i*prime[j]<maxn;j++)
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
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    getprime();
    int n;
    cin>>n;
    int flag=-1;
    int i;
    if(n>=3)
    {
        wfor(i,1,n)
        {
            edge.push_back(make_pair(i,i+1));
        }
        edge.push_back(make_pair(n,1));
        ll maxnum=n+n/2;
        int now=1;
        wfor(i,n,maxnum+1)
        {
            if(isprime[i])
            {
                flag=1;
                break;
            }
            edge.push_back(make_pair(now,n/2+now));
            now++;
        }
    }else
    {
        flag=-1;
    }
    if(flag!=-1)
    {
        cout<<edge.size()<<endl;
        for(auto k:edge)
        {
            cout<<k.first<<" "<<k.second<<endl;
        }
    }else
        cout<<-1<<endl;
    return 0;
}
