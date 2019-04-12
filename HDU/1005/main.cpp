#include <iostream>
#include<cmath>
using namespace std;
struct ju_zheng
{
    long long q[2][2];
};
ju_zheng ksm(ju_zheng a,long long b,long long mod);
ju_zheng cheng(ju_zheng a,ju_zheng b,long long mod);
int main()
{
    std::ios::sync_with_stdio(false);
    long long a,b,n;
    while(cin>>a>>b>>n)
    {
        if(a==0&&b==0&&n==0)
            break;
        ju_zheng res={0,0,0,0};
        ju_zheng t={0,1,
                    b,a};
        if(n>2)
        {
            res=ksm(t,n-2,7);
            cout<<(res.q[0][1]+res.q[0][0])%7<<endl;
        }else
        {
            cout<<1%7<<endl;
        }
    }
    return 0;
}
ju_zheng ksm(ju_zheng a,long long b,long long mod)
{
    ju_zheng res={1,0,0,1};
    while(b>0)
    {
        if(b&1)
        {
            res=cheng(res,a,mod);
        }
        b>>=1;
        a=cheng(a,a,mod);
    }
    return res;
}
ju_zheng cheng(ju_zheng a,ju_zheng b,long long mod)
{
    int i,j,k;
    ju_zheng res={0,0,0,0};
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                res.q[i][j]+=(a.q[i][k]%mod*b.q[k][j]%mod)%mod;
            }
            res.q[i][j]%=mod;
        }
    }
    return res;
}
