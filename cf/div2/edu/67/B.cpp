#include <iostream>
#include <vector> 
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
const int maxn=2e5+5;
vector< int> pos[26];
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
    wfor(i,0,n)
    {
        pos[s[i]-'a'].push_back(i+1);
    }
    int m;
    cin>>m;
    wfor(i,0,m)
    {
        cin>>s;
        int j;
        int ans=0;
        int cnt[26]={0};
        wfor(j,0,s.length())
        {
            ans=max(ans,pos[s[j]-'a'][cnt[s[j]-'a']]);
            cnt[s[j]-'a']++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
