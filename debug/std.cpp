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
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int i;
        int num[1005]={0};
        wfor(i,0,n)
        {
            int u,v;
            cin>>u>>v;
            int j;
            wfor(j,u,v+1)
                num[j]++;
        }
        wfor(i,1,l+1)
            cout<<num[i]<<" ";
        cout<<endl;
    }
    return 0;
}
