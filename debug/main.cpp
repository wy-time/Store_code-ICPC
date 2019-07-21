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
const int maxn=1005;
int num[maxn];
int ans[maxn];
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
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
    int n,m;
    while(cin>>n>>m)
    {
        int i;
        wfor(i,0,n)
        {
            cin>>num[i];
        }
        if(n==1)
        {
            cout<<"Yes"<<endl;
            cout<<"m"<<endl;
        }else
        {
            int value=num[0]*num[1]/gcd(num[0],num[1]);
            wfor(i,2,n)
            {
                value=value*num[i]/gcd(value,num[i]);
            }
            int sum=0;
            int cnt=1;
            int temp=value;
            while(sum<m)
            {
                value=temp*cnt;
                sum=0;
                wfor(i,0,n)
                {
                    ans[i]=value/num[i];
                    sum+=ans[i];
                }
                cnt++;
            }
            if(sum==m)
            {
                cout<<"Yes"<<endl;
                wfor(i,0,n-1)
                {
                    cout<<ans[i]<<" ";
                }
                cout<<ans[i]<<endl;
            }else
            cout<<"No"<<endl;
        }
    }
    return 0;
}
