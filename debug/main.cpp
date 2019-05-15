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
    int i;
    int cnt=(n-11)/2;
    int len=n;
    wfor(i,0,len)
    {
        if(cnt<=0)
            break;
        if(s[i]=='8')
        {
            s.erase(i,1);
            i--;
            len--;
            cnt--;
        }
    }
    n=(n-11)/2;
    wfor(i,0,n)
    {
        if(s[i]!='8')
        {
            s.erase(i,1);
            i--;
            n--;
        }else
            break;
    }
    if(s[0]=='8')
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
