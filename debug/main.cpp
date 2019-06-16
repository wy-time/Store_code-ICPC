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
    wfor(i,1,n+1)
    {
        cin>>num[i];
    }
    sort(num+1,num+n+1);
    int l=1;
    int r=n/2+1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        int flag=1;
        wfor(i,1,mid+1)
        {
            if(num[n-mid+i]-num[i]<k)
            {
                flag=0;
                break;
            }
        }
        if(flag)
            l=mid+1;
        else
            r=mid-1;
    }
    cout<<r<<endl;
    return 0;
}
