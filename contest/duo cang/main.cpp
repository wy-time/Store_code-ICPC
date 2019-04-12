#include <iostream>
#include<cstring>
using namespace std;
long long dp[5];
long long mod=2000120420010122LL;
char s[200005];
int main()
{
    std::ios::sync_with_stdio(false);
    char t[6]="cwbc";
    int i,j;
    while(cin>>s)
    {
        memset(dp,0,sizeof(dp));
        int len=strlen(s);
        dp[0]=1;
        for(i=1;i<=len;i++)
        {
            s[i-1]=tolower(s[i-1]);
            for(j=4;j>0;j--)
            {
                if(s[i-1]==t[j-1])
                    dp[j]=dp[j]%mod+dp[j-1]%mod;-
            }
        }
        cout<<dp[4]<<endl;
    }
    return 0;
}
