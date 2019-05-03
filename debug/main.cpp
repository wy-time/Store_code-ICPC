#include <iostream>
#include <cstring> 
#include <queue> 
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
int ans[maxn];
struct st
{
    int num;
    int id;
};
struct rule 
{
    bool operator()(const st &a,const st&b)
    {
        return a.num<b.num;
    }
};
priority_queue<st,vector<st>,rule>qu;
int _next[maxn];
int pre[maxn];
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
    st num;
    wfor(i,0,n)
    {
        cin>>num.num;
        num.id=i;
        qu.push(num);
        if(i!=0)
            pre[i]=i-1;
        else
            pre[i]=-1;
        if(i!=n-1)
            _next[i]=i+1;
        else
            _next[i]=-1;
    }
    int flag=1;
    wfor(i,0,n)
    {
        if(qu.empty())
            break;
        num=qu.top();
        qu.pop();
        while(ans[num.id]!=0&&!qu.empty())
        {
            num=qu.top();
            qu.pop();
        }
        if(ans[num.id]!=0)
            break;
        int cnt=0;
        int pos=num.id;
        while(cnt<=k)
        {
            if(_next[pos]==-1)
            {
                pos=-1;
                break;
            }
            pos=_next[pos];
            cnt++;
        }
        int end=pos;
        cnt=0;
        pos=num.id;
        while(cnt<=k)
        {
            if(pre[pos]==-1)
            {
                pos=-1;
                break;
            }
            pos=pre[pos];
            cnt++;
        }
        int be=pos;
        pos=num.id;
        int temp=0;
        cnt=0;
        while(cnt<=k)
        {
            temp=-1;
            if(ans[pos]==0)
            {
                ans[pos]=flag;
                cnt++;
                temp=pos;
            }
            pos=_next[pos];
            if(temp!=-1)
            {
                _next[temp]=end;
                pre[temp]=be;
            }
            if(pos==-1)
                break;
        }
        cnt=0;
        pos=max(num.id-1,-1);
        while(cnt<k&&pos!=-1)
        {
            temp=-1;
            if(ans[pos]==0)
            {
                ans[pos]=flag;
                cnt++;
                temp=pos;
            }
            pos=pre[pos];
            if(temp!=-1)
            {
                _next[temp]=end;
                pre[temp]=be;
            }
            if(pos==-1)
                break;
        }
        _next[be]=end;
        pre[end]=be;
        flag=flag==1?2:1;
    }
    wfor(i,0,n)
    {
        cout<<ans[i];
    }
    return 0;
}
