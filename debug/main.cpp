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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a,b,c;
        cin>>a>>b>>c;
        string s;
        cin>>s;
        int len=s.size();
        int i;
        int cnt=0;
        string ans=s;
        wfor(i,0,len)
        {
            if(s[i]=='R'&&b>0)
            {
                ans[i]='P';
                cnt++;
                b--;
            }else if(s[i]=='P'&&c>0)
            {
                ans[i]='S';
                cnt++;
                c--;
            }else if(s[i]=='S'&&a>0)
            {
                ans[i]='R';
                a--;
                cnt++;
            }else
                ans[i]=' ';
        }
        wfor(i,0,n)
        {
            if(ans[i]==' ')
            {
                if(a>0)
                {
                    a--;
                    ans[i]='R';
                }else if(b>0)
                {
                    b--;
                    ans[i]='P';
                }else if(c>0)
                {
                    c--;
                    ans[i]='S';
                }
            }
        }
        int need=n/2+(n%2!=0);
        if(cnt>=need)
        {
            cout<<"YES"<<endl;
            cout<<ans<<endl;
        }else
            cout<<"NO"<<endl;
    }
    return 0;
}
