#include <iostream>
#include <algorithm> 
#include <unordered_map> 
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
const int maxn=4e5+5;
unordered_map<int,int>ma;
int sum[maxn];
struct st
{
    int val;
    int cnt;
    bool operator <(const st&other)const
    {
        return val<other.val;
    }
};
st num[maxn];
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
    int n,I;
    cin>>n>>I;
    int i;
    wfor(i,0,n)
    {
        int t;
        cin>>t;
        if(ma.count(t)==0)
            ma.insert(make_pair(t,1));
        else
            ma[t]++;
    }
    int cnt=0;
    for(auto k:ma)
    {
        num[cnt++].val=k.first;
        num[cnt++].cnt=k.second;
    }
    int need=(8*I)/n;
    if(need>=19)
        cout<<0<<endl;
    else
    {
        need=1<<need;
        if(cnt<=need)
            cout<<0<<endl;
        else
        {
            sort(num,num+cnt);
            sum[1]=num[0].cnt;
            wfor(i,2,cnt+1)
            {
                sum[i]=sum[i-1]+num[i-1].cnt;
            }
            ll ans=-1e10;
            wfor(i,1,cnt-need+2)
            {
                if(sum[i+need-1]-sum[i-1]>ans)
                    ans=sum[i+need-1]-sum[i-1];
            }
            cout<<n-ans<<endl;
        }
    }
    return 0;
}
