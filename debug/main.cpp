#include <iostream>
#include <cstring> 
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
const ll mod=2147493647;
struct Matrix
{
    ll ma[7][7];
};
Matrix mul(Matrix a,Matrix b)
{
    Matrix c;
    memset(c.ma,0,sizeof(c.ma));
    int i,j,k;
    wfor(i,0,7)
    {
        wfor(j,0,7)
        {
            wfor(k,0,7)
            {
                c.ma[i][j]+=a.ma[i][k]*b.ma[k][j]%mod;
                c.ma[i][j]%=mod;
            }
        }
    }
    return c;
}
Matrix ksm(Matrix a,ll b)
{
    Matrix ans;
    memset(ans.ma,0,sizeof(ans.ma));
    int i;
    wfor(i,0,7)
    {
        ans.ma[i][i]=1;
    }
    while(b)
    {
        if(b&1)
            ans=mul(ans,a);
        a=mul(a,a);
        b>>=1;
    }
    return ans;
}
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
    int t;
    cin>>t;
    Matrix ori;
    memset(ori.ma,0,sizeof(ori.ma));
    ori.ma[0][0]=1;
    ori.ma[0][1]=1;
    ori.ma[1][0]=2;
    ori.ma[2][0]=1;
    ori.ma[2][2]=1;
    ori.ma[3][0]=4;
    ori.ma[3][2]=4;
    ori.ma[3][3]=1;
    ori.ma[4][0]=6;
    ori.ma[4][2]=6;
    ori.ma[4][3]=3;
    ori.ma[4][4]=1;
    ori.ma[5][0]=4;
    ori.ma[5][2]=4;
    ori.ma[5][3]=3;
    ori.ma[5][4]=2;
    ori.ma[5][5]=1;
    ori.ma[6][0]=1;
    ori.ma[6][2]=1;
    ori.ma[6][3]=1;
    ori.ma[6][4]=1;
    ori.ma[6][5]=1;
    ori.ma[6][6]=1;
    int fir[7];
    fir[2]=16;
    fir[3]=8;
    fir[4]=4;
    fir[5]=2;
    fir[6]=1;
    while(t--)
    {
        ll n;
        cin>>n;
        int a,b;
        cin>>a>>b;
        ll ans=0;
        fir[0]=b%mod;
        fir[1]=a%mod;
        if(n>2)
        {
            Matrix temp=ksm(ori,n-2);
            int i;
            wfor(i,0,7)
            {
                ans+=fir[i]*temp.ma[i][0];
                ans%=mod;
            }
            cout<<ans<<endl;
        }else
        {
            if(n==1)
                cout<<a%mod<<endl;
            else
                cout<<b%mod<<endl;
        }
    }
    return 0;
}
