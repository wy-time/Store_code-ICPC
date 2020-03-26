#include <iostream>
#include <map> 
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
map <int,int,greater<int> >ma;
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
        ma.clear();
        int n;
        cin>>n;
        int i;
        wfor(i,0,n)
        {
            int a;
            cin>>a;
            if(ma.count(a)==0)
                ma.insert(make_pair(a,1));
            else
                ma[a]++;
        }
        ll ans=0;
        for (auto k:ma)
        {
            if(k.first%2==0)
            {
                if(ma.count(k.first/2)==0)
                    ma.insert(make_pair(k.first/2,k.second));
                else
                    ma[k.first/2]+=k.second;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
