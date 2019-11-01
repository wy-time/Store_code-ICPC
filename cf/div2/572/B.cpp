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
const int maxn=1e5+5;
int num[maxn];
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
    int n;
    cin>>n;
    int i;
    wfor(i,0,n)
    {
        cin>>num[i];
    }
    sort(num,num+n,greater<int>());
    if(num[0]>=num[1]+num[2])
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        int cnt=0;
        for(i=0;2*i<n;i++)
            ans[cnt++]=num[2*i];
        int flag=1;
        i--;
        if(2*i==n-1)
            i--;
        else
        {
            i++;
            flag=-1;
        }
        for(;2*i+flag>0;i--)
            ans[cnt++]=num[2*i+flag];
        wfor(i,0,n)
            cout<<ans[i]<<" ";
    }
    return 0;
}
