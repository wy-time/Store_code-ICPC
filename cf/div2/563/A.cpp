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
const int maxn=20005;
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
    int n;
    cin>>n;
    n*=2;
    int i;
    ll sum=0;
    wfor(i,0,n)
    {
        cin>>num[i];
        sum+=num[i];
    }
    sort(num,num+n);
    ll sum1=0;
    wfor(i,0,n/2)
    {
        sum1+=num[i];
    }
    if(sum1*2==sum)
        cout<<-1<<endl;
    else
    {
        wfor(i,0,n)
        {
            cout<<num[i]<<" ";
        }
    }
    return 0;
}
