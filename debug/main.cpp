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
    int n,t;
    cin>>n>>t;
    int i;
    int ans=1e9;
    int res=0;
    wfor(i,0,n)
    {
        int temp=t;
        int a,b;
        cin>>a>>b;
        if(t>a)
        {
            temp-=a;
            if(temp%b==0)
                temp/=b;
            else
                temp=temp/b+1;
        }else
            temp=0;
        if(temp*b+a<ans)
        {
            ans=temp*b+a;
            res=i+1;
        }
    }
    cout<<res<<endl;
    return 0;
}
