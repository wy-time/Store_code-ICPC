#include <iostream>
#include <string> 
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
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    int i;
    s=s.substr(n-x);
    int len=s.size();
    int ans=0;
    wfor(i,0,len-y-1)
    {
        if(s[i]!='0')
            ans++;
    }
    if(s[i]!='1')
        ans++;
    wfor(i,i+1,len)
    {
        if(s[i]!='0')
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
