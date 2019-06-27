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
    string s;
    cin>>s;
    int i=0;
    string ans="";
    while(i+1<n)
    {
        int j=i+1;
        if(s[i]!=s[i+1])
        {
            ans+=s[i];
            ans+=s[i+1];
            i=j+1;
        }else
        {
            while(s[i]==s[j]&&j<n)
            {
                j++;
            }
            if(j<n)
            {
                ans+=s[i];
                ans+=s[j];
            }
            i=j+1;
        }
    }
    cout<<n-ans.size()<<endl;
    cout<<ans<<endl;
    return 0;
}
