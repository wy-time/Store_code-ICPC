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
vector<int>sumw;
vector<int>sumo;
const int maxn=1e6+5;
ll sum[maxn];
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
    int len=s.size();
    int i;
    int cnt=0;
    int cnt2=0;
    int flag=0;
    wfor(i,0,len)
    {
        if(s[i]=='v')
        {
            cnt++;
            if(cnt2>0&&!sumw.empty())
            {
                if(flag==1&&!sumo.empty())
                {
                    *sumo.rbegin()+=cnt2;
                }else
                    sumo.push_back(cnt2);
            }
            flag=0;
            cnt2=0;
        }else
        {
            if(cnt>1)
            {
                sumw.push_back(cnt-1);
                flag=0;
            }
            else if(cnt!=0)
                flag=1;
            cnt=0;
            cnt2++;
        }
    }
    if(cnt2>0&&!sumw.empty())
    {
        if(flag==1&&!sumo.empty())
        {
            *sumo.rbegin()+=cnt2;
            flag=0;
        }else
            sumo.push_back(cnt2);
    }
    if(cnt>1)
        sumw.push_back(cnt-1);
    len=sumw.size();
    int n=len;
    wfor(i,0,len)
    {
        if(i==0)
            sum[i]=sumw[i];
        else
            sum[i]=sum[i-1]+sumw[i];
    }
    len=sumo.size();
    ll ans=0;
    wfor(i,0,len)
    {
        ans+=1ll*sum[i]*(sum[n-1]-sum[i])*sumo[i];
    }
    cout<<ans<<endl;
    return 0;
}
