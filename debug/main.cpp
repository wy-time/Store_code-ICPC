#include <iostream>
#include <string> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}
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
    ll n;
    char ma[300];
    ma['a']=0;
    ma['v']=1;
    ma['i']=2;
    ma['n']=3;
    while(cin>>n)
    {
        string s;
        cin>>s;
        ll i;
        ll num[4]={0};
        wfor(i,0,n)
        {
            if(s[i]=='a'||s[i]=='v'||s[i]=='i'||s[i]=='n')
                num[ma[s[i]]]++;
        }
        ll up=num[0]*num[1]*num[2]*num[3];
        ll down=n*n*n*n;
        ll g=gcd(up,down);
        cout<<up/g<<"/"<<down/g<<endl;
    }
    return 0;
}
