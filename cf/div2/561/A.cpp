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
    int n;
    cin>>n;
    int i;
    int num[26]={0};
    wfor(i,0,n)
    {
        string s;
        cin>>s;
        num[s[0]-'a']++;
    }
    int ans=0;
    wfor(i,0,26)
    {
        if(num[i]>=3)
        {
            int t1=num[i]/2;
            int t2=num[i]-t1;
            ans+=t1*(t1-1)/2;
            ans+=t2*(t2-1)/2;
        }
    }
    cout<<ans<<endl;
    return 0;
}
