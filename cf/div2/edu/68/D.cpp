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
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(k%3==0)
        {
            if(n%(k+1)==k)
                cout<<"Alice"<<endl;
            else
            {
                n%=(k+1);
                if(n%3==0)
                    cout<<"Bob"<<endl;
                else 
                    cout<<"Alice"<<endl;
            }
        }else
        {
            if((n+3)%3==0)
                cout<<"Bob"<<endl;
            else
                cout<<"Alice"<<endl;
        }
    }
    return 0;
}
