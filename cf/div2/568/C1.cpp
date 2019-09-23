#include <iostream>
#include <set> 
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
int num[maxn];
int ans[maxn];
multiset<int,greater<int>>qu;
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
    int n,m;
    cin>>n>>m;
    int i;
    wfor(i,0,n)
    {
        cin>>num[i];
    }
    ll sum=0;
    wfor(i,0,n)
    {
        if(sum+num[i]<=m)
        {
            ans[i]=i-qu.size();
            sum+=num[i];
            qu.insert(num[i]);
        }else
        {
            ll temp=sum;
            ans[i]=i-qu.size();
            for(auto k:qu)
            {
                ans[i]++;
                temp-=k;
                if(temp+num[i]<=m)
                    break;
            }
            if(num[i]<*qu.begin())
            {
                sum-=*qu.begin();
                sum+=num[i];
                qu.erase(qu.begin());
                qu.insert(num[i]);
            }
        }
        cout<<ans[i]<<" ";
    }
    return 0;
}
