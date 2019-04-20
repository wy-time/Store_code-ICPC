#include<bits/stdc++.h>
 
#define LL long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
using namespace std;
 
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
LL powmod(LL a,LL b,LL MOD){LL ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}
const int N = 1e6 +11;
LL n,a[N],b[N],l[N],r[N];
LL top=0,s[N];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    // for(int i=1;i<=n;i++)a[i]=1;
    for(int i=1;i<=n;i++)b[i]=a[i];
    for(int i=1;i<=n;i++)a[i]+=a[i-1];
    for(int i=1;i<=n;i++){
        while(top&&b[s[top]]>=b[i])top--;
        if(!top)l[i]=0;
        else l[i]=s[top];
        s[++top]=i;
    }
    top=0;
    for(int i=n;i>=1;i--){
        while(top&&b[s[top]]>=b[i])top--;
        if(!top)r[i]=n;
        else r[i]=s[top]-1;
        s[++top]=i;
    }
    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]>0)
            ans=max(ans,1ll*b[i]*(a[r[i]]-a[l[i]]));
        else
        {
            LL temp=b[i];
            int j;
            LL ts=b[i];
            LL tempr=b[i];
            for(j=i-1;j>l[i];j--)
            {
                ts+=b[j];
                temp=min(ts,temp);
            }
            ts=b[i];
            for(j=i+1;j<=r[i];j++)
            {
                ts+=b[j];
                tempr=min(tempr,ts);
            }
            if(temp<0&&tempr<0)
            {
                ans=max(ans,(temp+tempr-b[i])*b[i]);
            }else
            {
                ans=max(ans,min(temp,tempr)*b[i]);
            }
        }
    }   
    cout<<ans<<endl;
    return 0;
}
