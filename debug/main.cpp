#include <iostream>
#include <vector> 
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
const int maxn=2005;
int num2[maxn];
int num[maxn];
int _next[maxn][maxn];
int vis[maxn];
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
    int i;
    memset(_next,-1,sizeof(_next));
    wfor(i,0,n)
    {
        cin>>num2[i];
        num[i]=num2[i];
    }
    sort(num2,num2+n);
    int p=unique(num2,num2+n)-num2;
    wfor(i,0,n)
    {
        num[i]=lower_bound(num2,num2+p,num[i])-num2;
    }
    int j;
    mfor(i,n-1,1)
    {
        wfor(j,0,p)
        {
            _next[i-1][j]=_next[i][j];
            _next[i-1][num[i]]=i;
        }
    }
    int l,r=0;
    int ans=1e9;
    int last=0;
    int minl=1e9;
    vector<int>v;
    int cnt=0;
    wfor(i,0,n)
    {
        if(_next[i][num[i]]!=-1&&!vis[num[i]])
        {
            cnt++;
            vis[num[i]]=1;
        }
    }
    int cnt2=0;
    wfor(i,0,n)
    {
        if(_next[i][num[i]]!=-1)
        {
            l=min(i,minl);
            r=0;
            wfor(j,i,n)
            {
                if(_next[j][num[j]]!=-1)
                    r=max(last,j);
            }
            ans=min(ans,r-l+1);
            if(i>=minl)
                break;
            cnt2++;
            int temp=_next[i][num[i]];
            last=max(last,_next[i][num[i]]);
            v.push_back(_next[i][num[i]]);
            minl=min(minl,_next[i][num[i]]);
            while(_next[temp][num[i]]!=-1)
            {
                v.push_back(_next[temp][num[i]]);
                minl=min(minl,_next[temp][num[i]]);
                last=max(last,_next[temp][num[i]]);
                temp=_next[temp][num[i]];

            }
        }
    }
    if(!v.empty()&&cnt==cnt2)
        ans=min(*max_element(v.begin(),v.end())-*min_element(v.begin(),v.end())+1,ans);
    if(ans==1e9)
        ans=0;
    cout<<ans<<endl;
    return 0;
}
