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
    char ma[5]={'a','e','i','o','u'};
    if(n<25)
    {
        cout<<-1<<endl;
    }else
    {
        int h=0,l=0;
        int i;
        for(i=5;i*i<=n;i++)
        {
            if(n%i==0)
            {
                h=i;
                l=n/i;
            }
        }
        if(h==0&&l==0)
        {
            cout<<-1<<endl;
        }else
        {
            wfor(i,0,h)
            {
                int j;
                wfor(j,0,l)
                {
                    if(j!=0)
                        cout<<(char)(ma[(i%5+j%5)%5]);
                    else 
                        cout<<(char)(ma[i%5]);
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
