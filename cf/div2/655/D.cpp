#include <iostream>
#include <deque> 
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
int num2[maxn*2];
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
    int n;
    cin>>n;
    int i;
    wfor(i,0,n)
    {
        cin>>num[i];
    }
    for(i=0;i<n;i+=2)
    {
        num2[i/2]=num[i];
    }
    for(i=1;i<n;i+=2)
    {
        num2[n/2+(i+1)/2]=num[i];
    }
    wfor(i,n,2*n)
    {
        num2[i]=num2[i-n];
    }
    int need=(n+1)/2;
    deque<int>qu;
    ll sum=0;
    ll ans=0;
    wfor(i,0,need)
    {
        sum+=num2[i];
        qu.push_back(num2[i]);
    }
    ans=sum;
    wfor(i,need,2*n)
    {
        sum-=qu.front();
        qu.pop_front();
        sum+=num2[i];
        qu.push_back(num2[i]);
        ans=max(sum,ans);
    }
    cout<<ans<<endl;
    return 0;
}
