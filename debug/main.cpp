#include <iostream>
#include <cmath> 
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
    int a,b;
    while(cin>>a>>b)
    {
        int x=1;
        int l=max(0,(int)ceil((-1.0*a+sqrt(1.0*a*a-4.0*b+0.5))/(-2.0)));
        int r=floor((-1.0*a-sqrt(1.0*a*a-4.0*b+0.5))/(-2.0));
        int flag=0;
        wfor(x,l,r+1)
        {
            if(a-x<x)
                break;
            int n=gcd(a,x);
            if(x*(a-x)==n*b)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"No Solution"<<endl;
        else 
            cout<<x<<" "<<a-x<<endl;
    }
    return 0;
}
