#include <bits/stdc++.h>
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
typedef long long LL;
void read(LL &x) {
char ch = getchar(); x = 0;
for (; ch < '0' || ch > '9'; ch = getchar());
for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
using namespace std;
const double eps=1e-9;
const int maxn = 100001;
const int MAX=1e4+5;
LL prime[MAX];
int equa(double a,double b)
{
    if(fabs(a-b)<eps)
        return 1;
    else
        return 0;
}
void get_prime()
{
    LL i;
    wfor(i,2,MAX)
    {
        if(prime[i]==0)
            prime[++prime[0]]=i;
        int j;
        for(j=1;j<=prime[0]&&prime[j]*i<MAX;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
LL mul(LL a,LL b,LL mod) {
    if(!a) return 0;
    return ((a&1)*b%mod + (mul(a>>1,b,mod)<<1)%mod)%mod;
}
LL quickPow(LL a,LL d,LL n) {
    LL ret = 1;
    while(d) {
        if(d&1) ret = mul(ret,a,n);
        d >>= 1;
        a = mul(a,a,n);
    }
    return ret;
}
bool check(LL a,LL d,LL n) {
    if(n == a) return true;
    while(~d&1) d >>= 1;
    LL t = quickPow(a,d,n);
    while(d < n-1 && t != 1 && t != n-1) {
        t = mul(t,t,n);
        d <<= 1;
    }
    return (d&1) || t == n-1;
}
bool isP(LL n) {
    if(n == 2) return true;
    if(n < 2 || 0 == (n&1)) return false;
    static int p[5] = {2,3,7,61,24251};
    for(int i = 0; i < 5; ++i)
        if(!check(p[i],n-1,n)) return false;
    return true;
}
int main() {
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("/home/time/debug/debug/in","r",stdin);
    freopen("/home/time/debug/debug/out","w",stdout);
    #endif   
    LL x;
    LL t;
    get_prime();
    //scanf("%d",&t);
    read(t);
    while(t--){
        read(x);
        if(x == 1) {
            puts("1");
            continue;
        }
        if(isP(x)){
            puts("1");
            continue;
        }
        int i;
        int res=100000000;
        for(i=1;i<=prime[0]&&prime[i]*prime[i]<=x;i++)
        {
            if(x%prime[i]==0)
            {
                int cnt=0;
                while(x%prime[i]==0)
                {
                    cnt++;
                    x/=prime[i];
                }
                res=min(res,cnt);
                if(res==1)
                    break;
            }
        }
        if(res==1)
        {
            puts("1");
            continue;
        }
        if(x == 1) {
            printf("%d\n",res);
            continue;
        }
        if(isP(x)){
            puts("1");
            continue;
        }
        double temp=pow(x,-4.0);
        if(equa(temp*temp*temp*temp,x))
        {
            res=min(res,4);
            temp=pow(x,-2.0);
            if(equa(temp*temp,x))
                res=min(2,res);
        }else
        {
            temp=pow(x,-3.0);
            if(equa(temp*temp*temp,x))
            {
                res=min(res,3);
            }else
                res=1;
        }
        printf("%d\n",res);
    }
    return 0;
}
