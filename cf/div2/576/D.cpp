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
const int maxn=2e5+5;
int num[maxn];
int lastop[maxn];
int maxchange[maxn];
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
    wfor(i,1,n+1)
    {
        cin>>num[i];
    }
    int q;
    cin>>q;
    wfor(i,1,q+1)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int pos,number;
            cin>>pos>>number;
            num[pos]=number;
            lastop[pos]=i;
        }else
        {
            int number;
            cin>>number;
            maxchange[i]=number;
        }
        
    }
    mfor(i,q,0)
    {
        maxchange[i]=max(maxchange[i],maxchange[i+1]);
    }
    wfor(i,1,n+1)
    {
        if(num[i]<maxchange[lastop[i]])
            num[i]=maxchange[lastop[i]];
        cout<<num[i]<<" ";
    }
    return 0;
}
