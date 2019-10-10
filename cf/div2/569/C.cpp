#include <iostream>
#include <deque> 
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
const int maxn=1e5+5;
int num[maxn];
pair<int,int>ans[maxn];
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
    int n,q;
    cin>>n>>q;
    int i;
    deque<int>qu;
    int maxnum=0;
    wfor(i,0,n)
    {
        int t;
        cin>>t;
        qu.push_back(t);
        maxnum=max(t,maxnum);
    }
    int pre=0;
    while(qu.front()!=maxnum)
    {
        pre++;
        int t1=qu.front();
        qu.pop_front();
        int t2=qu.front();
        qu.pop_front();
        ans[pre].first=t1;
        ans[pre].second=t2;
        qu.push_front(max(t1,t2));
        qu.push_back(min(t1,t2));
    }
    wfor(i,0,n)
    {
        num[i]=qu.front();
        qu.pop_front();
    }
    wfor(i,0,q)
    {
        ll m;
        cin>>m;
        if(m<=pre)
        {
            cout<<ans[m].first<<" "<<ans[m].second<<endl;
        }else
        {
            m-=pre;
            m--;
            m%=(n-1);
            cout<<maxnum<<" "<<num[m+1]<<endl;
        }
    }
    return 0;
}
