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
    string s;
    cin>>s;
    int k;
    cin>>k;
    int i;
    int len=s.size();
    string ans="";
    int now=0;
    wfor(i,0,len)
    {
        if(s[i]=='?'||s[i]=='*')
            now++;
    }
    now=len-now;
    wfor(i,0,len)
    {
        if(s[i+1]=='*')
        {
            if(k>now)
            {
                int j;
                wfor(j,now,k+1)
                {
                    ans+=s[i];
                }
                now=k;
            }else if(k<now)
            {
                now--;
                continue;
            }else
                ans+=s[i];
        }else if(s[i+1]=='?')
        {
            if(k>now)
            {
                ans+=s[i];
            }else if(k<now)
            {
                now--;
                continue;
            }else
                ans+=s[i];
        }else if(s[i]!='*'&&s[i]!='?')
            ans+=s[i];
    }
    if(now!=k)
        cout<<"Impossible"<<endl;
    else
        cout<<ans<<endl;
    return 0;
}
