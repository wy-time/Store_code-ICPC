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
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i;
        wfor(i,1,n+1)
        {
            int k;
            cin>>k;
            num[k]=i;
        }
        int flag=0;
        int l=1,r=n;
        mfor(i,n,1)
        {
            if(num[i]+1<=r&&num[i]-1>=l)
            {
                flag=1;
                cout<<"YES"<<endl;
                cout<<num[i]-1<<" "<<num[i]<<" "<<num[i]+1<<endl;
                break;
            }else
            {
                if(num[i]==r)
                    r=num[i]-1;
                else if(num[i]==l)
                    l=num[i]+1;
            }
        }
        if(flag!=1)
            cout<<"NO"<<endl;
    }
    return 0;
}
