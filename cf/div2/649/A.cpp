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
const int maxn=1e5+5;
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
        ll sum=0;
        int n,x;
        cin>>n>>x;
        int i;
        int posf=-1;
        int posb=-1;
        wfor(i,0,n)
        {
            cin>>num[i];
            sum+=num[i];
            if(num[i]%x!=0)
            {
                if(posf==-1)
                    posf=i+1;
                posb=n-i;
            }
        }
        if(sum%x==0)
        {
            int ans;
            if(posf==-1)
                ans=-1;
            else
                ans=max(n-posf,n-posb);
            cout<<ans<<endl;
        }else
            cout<<n<<endl;
    }
    return 0;
}
