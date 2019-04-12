#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef long long LL;
const LL p=998244353;
LL fac[100005];
LL n,m;
LL quick_mod(LL a, LL b)
{
    LL ans = 1;
    a %= p;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % p;
            b--;
        }
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}

LL C(LL n, LL m)
{
    if(n < m) return 0;
    return fac[n] * quick_mod(fac[m] * fac[n-m], p - 2) % p;
}

LL Lucas(LL n, LL m)
{
    if(m == 0) return 1;
    return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

int main()
{
    std::ios::sync_with_stdio(false);
    fac[0]=1;
    for(int i=1; i<100005; i++)
        fac[i] = (fac[i-1] * i) % p;
    LL t;
    cin>>t;
    while(t--)
    {
        LL a,b;
        cin>>a>>b>>n>>m;
        if(n<m)
            cout<<0<<endl;
        else
            cout<<(quick_mod(a,n-m)%p*Lucas(n-1,m-1)%p*quick_mod(b,m-1)%p)%p<<endl;
    }
    return 0;
}
