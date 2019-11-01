#include <iostream>
#include <cstring> 
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
int ma[26];
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
    int q;
    cin>>q;
    while(q--)
    {
        memset(ma,0,sizeof(ma));
        string s,t,p;
        cin>>s>>t>>p;
        int i=0,j=0;
        int lens=s.size();
        int lent=t.size();
        int lenp=p.size();
        wfor(i,0,lenp)
        {
            ma[p[i]-'a']++;
        }
        i=0;
        int now=lens;
        int flag=1;
        while(j<lent)
        {
            if((i<lens&&s[i]!=t[j])||i==lens)
            {
                if(ma[t[j]-'a']!=0)
                {
                    ma[t[j]-'a']--;
                    now++;
                    j++;
                }else
                {
                    flag=0;
                    break;
                }
            }else
            {
                i++;
                j++;
            }
        }
        if(!flag||now>lent)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
