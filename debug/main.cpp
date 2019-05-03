#include <iostream>
#include <cmath> 
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
    int ans=1e9;
    char aim[5]="ACTG";
    wfor(i,0,n-3)
    {
        int j;
        int temp=0;
        wfor(j,0,4)
        {
            int cnt='Z'-s[i+j];
            cnt+=aim[j]-'A'+1;
            cnt=min(cnt,abs(s[i+j]-aim[j]));
            temp+=cnt;
        }
        ans=min(temp,ans);
    }
    cout<<ans<<endl;
    return 0;
}
