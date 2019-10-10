#include <set> 
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(int &x) {
char ch = getchar(); x = 0;
for (; ch < '0' || ch > '9'; ch = getchar());
for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
const int maxn=1e6+5;
pair<int,int>ans[maxn];
set<pair<int,int>>check;
int main()
{
    //std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("/home/time/debug/debug/in","r",stdin);
    freopen("/home/time/debug/debug/out","w",stdout);
    #endif
    int n,m;
    //cin>>n>>m;
    read(n),read(m);
    int minrow=1;
    int maxrow=n;
    int mincow=1;
    int maxcow=m;
    int need=n*m;
    int cnt=0;
    while(cnt<need)
    {
        ans[cnt++]=make_pair(minrow,mincow);
        if(minrow!=maxrow||mincow!=maxcow)
            ans[cnt++]=make_pair(maxrow,maxcow);
        if(mincow==m)
        {
            minrow++;
            maxrow--;
            mincow=1;
            maxcow=m;
        }else
        {
            mincow++;
            maxcow--;
        }
    }
    int i;
    //pair<int,int>last=ans[0];
    //wfor(i,1,cnt)
    //{
    //    check.insert(make_pair(ans[i].first-last.first,ans[i].second-last.second));
    //    last=ans[i];
    //}
    //if(check.size()==n*m-1)
    //{
        wfor(i,0,cnt)
        {
            printf("%d %d\n",ans[i].first,ans[i].second);
            //cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
    //}else
        //printf("-1\n");
        //cout<<-1<<endl;
    return 0;
}
