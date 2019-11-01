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
    int n;
    cin>>n;
    int i;
    int flag=0;
    wfor(i,0,n)
    {
        int t;
        cin>>t;
        if(t%2==0)
            cout<<t/2<<endl;
        else
        {
            if(t<0)
            {
                if(flag==0)
                {
                    cout<<t/2-1<<endl;
                    flag=1;
                }else
                {
                    cout<<t/2<<endl;
                    flag=0;
                }
            }else
            {
                if(flag==0)
                {
                    cout<<t/2<<endl;
                    flag=1;
                }else
                {
                    cout<<t/2+1<<endl;
                    flag=0;
                }
            }
        }
    }
    return 0;
}
