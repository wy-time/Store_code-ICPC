#include <iostream>
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
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        std::string s;
        cin>>s;
        int i;
        int cntr=0,cnts=0,cntp=0;
        wfor(i,0,s.length())
        {
            if(s[i]=='R')
                cntr++;
            else if(s[i]=='S')
                cnts++;
            else
                cntp++;
        }
        char ans;
        if(cntr>=cnts&&cntr>=cntp)
        {
            ans='P';
        }else if(cnts>=cntr&&cnts>=cntp)
            ans='R';
        else
            ans='S';
        string res(s.length(),ans);
        cout<<res<<endl;
    }
    return 0;
}
