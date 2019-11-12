#include <iostream>
#include <vector> 
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
const int maxn=105;
int num[maxn];
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
    int tot=0;
    wfor(i,0,n)
    {
        cin>>num[i];
        tot+=num[i];
    }
    vector<int>ans;
    ans.push_back(1);
    int now=num[0];
    int sum=num[0];
    wfor(i,1,n)
    {
        if(num[i]*2<=now)
        {
            ans.push_back(i+1);
            sum+=num[i];
        }
    }
    if(sum*2>tot)
    {
        cout<<ans.size()<<endl;
        for(auto k:ans)
            cout<<k<<" ";
    }else
        cout<<0<<endl;
    return 0;
}
