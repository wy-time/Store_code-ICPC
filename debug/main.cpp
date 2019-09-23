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
    int n,k;
    cin>>n>>k;
    int i;
    string s;
    cin>>s;
    int cnt=0;
    if(s[0]!='1')
    {
        s[0]='1';
        cnt++;
    }
    wfor(i,1,n)
    {
        if(cnt>=k)
            break;
        if(s[i]!='0')
        {
            s[i]='0';
            cnt++;
        }
    }
    if(n==1&&k>=1)
        s[0]='0';
    cout<<s<<endl;
    return 0;
}
