#include <iostream>
#include <vector> 
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
int numa[maxn];
int numb[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    ll x,k,y;
    cin>>x>>k>>y;
    int i;
    wfor(i,0,n)
    {
        cin>>numa[i];
    }
    wfor(i,0,m)
    {
        cin>>numb[i];
    }
    int flag=1;
    int j=0;
    vector<pair<int,int>>v;
    int prel=0;
    int cle=0;
    wfor(i,0,n)
    {
        if(numa[i]==numb[j])
        {
            j++;
            if(flag==0)
            {
                flag=1;
                v.push_back(make_pair(prel,i-1));
                cle+=i-1-prel+1;
            }
        }else if(numa[i]!=numb[j])
        {
            if(flag==1)
            {
                flag=0;
                prel=i;
            }
        }
        if(j==m)
        {
            if(i+1<n)
            {
                v.push_back(make_pair(i+1,n-1));
                cle+=n-1-i;
            }
            break;
        }
    }
    int isok=1;
    ll ans=0;
    for(auto seg:v)
    {
        int l=seg.first,r=seg.second;
        int maxnum=0;
        wfor(j,l,r+1)
        {
            maxnum=max(maxnum,numa[j]);
        }
        int len=r-l+1;
        int eatcnt=r-l;
        if(l-1>=0&&numa[l-1]>maxnum)eatcnt=len;
        if(r+1<n&&numa[r+1]>maxnum)eatcnt=len;
        ll cost=1e18;
        wfor(j,0,eatcnt+1)
        {
            if((len-j)%k==0)
                cost=min(cost,j*y+(len-j)/k*x);
        }
        if(cost==1e18)
        {
            isok=0;
            break;
        }
        ans+=cost;
    }
    if(n-cle<m)
        isok=0;
    if(isok)
        cout<<ans<<endl;
    else
        cout<<"-1"<<endl;
    return 0;
}
