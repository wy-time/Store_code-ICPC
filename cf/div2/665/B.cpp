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
        int x1,y1,z1;
        int x2,y2,z2;
        cin>>x1>>y1>>z1;
        cin>>x2>>y2>>z2;
        int ans=0;
        ans+=min(z1,y2)*2;
        int temp=min(z1,y2);
        z1-=temp;
        y2-=temp;
        temp=min(z1,z2);
        z1-=temp;
        z2-=temp;
        temp=min(z1,x2);
        z1-=temp;
        x2-=temp;
        temp=min(x1,z2);
        x1-=temp;
        z2-=temp;
        temp=min(x1,y2);
        x1-=temp;
        y2-=temp;
        temp=min(x1,x2);
        x1-=temp;
        x2-=temp;
        temp=min(y1,x2);
        y1-=temp;
        x2-=temp;
        temp=min(y1,y2);
        y1-=temp;
        y2-=temp;
        temp=min(y1,z2);
        ans-=2*temp;
        cout<<ans<<endl;
    }

    return 0;
}
