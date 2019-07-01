#include <iostream>
#include <cmath> 
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
const double eps=1e-9;
bool equa(double a,double b)
{
    if(fabs(a-b)<eps)
        return true;
    else
        return false;
}
const int maxn=1e5+5;
double num[maxn];
int ans[maxn];
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
    wfor(i,0,n)
    {
        cin>>num[i];
    }
    double rest=0;
    rest=floor(num[0])-num[0];
    ans[0]=floor(num[0]);
    wfor(i,1,n)
    {
        if(rest<=0)
        {
            if(num[i]>0)
            {
                rest+=ceil(num[i])-num[i];
                ans[i]=ceil(num[i]);
            }else
            {
                rest+=ceil(num[i])-num[i];
                ans[i]=ceil(num[i]);
            }
        }else
        {
            if(num[i]>0)
            {
                rest+=floor(num[i])-num[i];
                ans[i]=floor(num[i]);
            }else
            {
                rest+=floor(num[i])-num[i];
                ans[i]=floor(num[i]);
            }
        }
    }
    wfor(i,0,n)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
