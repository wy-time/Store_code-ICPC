#include <iostream>
#include <cstring> 
#include <algorithm> 
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
int num[maxn];
int num2[maxn];
int vis[maxn];
void add(int x)
{
    int i;
    for(i=x;i<maxn;i+=(i&-i))
        vis[i]++;
}
int get_sum(int x)
{
    int i;
    int sum=0;
    for(i=x;i>0;i-=(i&-i))
        sum+=vis[i];
    return sum;
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
    int n,k;
    cin>>n>>k;
    int i;
    wfor(i,1,n+1)
    {
        cin>>num[i];
        num2[i]=num[i];
    }
    sort(num+1,num+1+n);
    sort(num2+1,num2+1+n);
    int ans=0;
    int use=0;
    wfor(i,1,n)
    {
        if(get_sum(i)-get_sum(i-1)==1)
            continue;
        use++;
        add(i);
        int pos=lower_bound(num+1,num+n+1,num[i]+k)-num;
        int last=n-pos+1-(use-get_sum(pos-1));
        if(last>0)
        {
            ans++;
            use++;
            add(n-last+1);
        }else
            break;
    }
    memset(vis,0,sizeof(vis));
    sort(num+1,num+1+n,greater<int>());
    use=0;
    int temp=0;
    wfor(i,1,n)
    {
        if(get_sum(i)-get_sum(i-1)==1)
            continue;
        use++;
        add(i);
        int pos=upper_bound(num2+1,num2+n+1,num[i]-k)-num2-1;
        if(pos==0)
            break;
        pos=n-pos+1;
        int last=n-pos+1-(use-get_sum(pos-1));
        if(last>0)
        {
            temp++;
            use++;
            add(n-last+1);
        }else
            break;
    }
    ans=max(temp,ans);
    cout<<ans<<endl;
    return 0;
}
