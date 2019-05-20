#include<bits/stdc++.h>
#define fi first
#define se second
#define bug cout<<"--------------"<<endl
using namespace std;
typedef long long LL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=1e9;
const LL llf=1e18;
const int mod=1e9+7;
const int maxn=1e6+10;
int n,x;
int ll[maxn],rr[maxn];
int l[maxn],r[maxn];
int main(){
    ios::sync_with_stdio(false);
    //freopen("in","r",stdin);
    cin>>n>>x;
    memset(l,0x3f3f3f,sizeof(l));
    memset(ll,0x3f3f3f,sizeof(ll));
    for(int i=1,d;i<=n;i++){
        cin>>d;
        l[d]=min(i,l[d]);
        r[d]=i;
    }
    for(int i=1;i<=x;i++){
        rr[i]=max(rr[i-1],r[i]);
    }
    for(int i=x;i>=1;i--){
        ll[i]=min(l[i],ll[i+1]);
    }
    int R=x;
    LL ans=0;
    while(ll[R]>=r[R-1]&&R>=1) R--;
    for(int i=0;i<x;i++){
        if(i!=0&&l[i]<rr[i-1]) break;
        while(R<=i+1||rr[i]>ll[R]){
            R++;
        }
        ans+=x-R+2;
    }
    cout<<ans<<endl;
    return 0;
}
