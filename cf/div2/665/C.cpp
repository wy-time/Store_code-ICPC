#include <iostream>
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
const int maxn=1e5+5;
int num[maxn];
pair<int,int>num2[maxn];
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i;
        wfor(i,0,n)
        {
            cin>>num[i];
            num2[i].first=num[i];
            num2[i].second=i;
        }
        sort(num2,num2+n);
        int flag=1;
        wfor(i,0,n)
        {
            if(num[i]!=num2[i].first)
            {
                int t=gcd(num[i],num2[i].first);
                if(t==num2[0].first)
                {
                    int pos=lower_bound(num2,num2+n,pair<int,int>{num[i],i})-num2;
                    swap(num[i],num[num2[i].second]);
                    num2[pos].second=num2[i].second;
                    num2[i].second=i;
                }
                else if(gcd(num[i],num2[0].first)==num2[0].first&&gcd(num2[i].first,num2[0].first)==num2[0].first)
                {
                    int pos=lower_bound(num2,num2+n,pair<int,int>{num[i],i})-num2;
                    swap(num[i],num[num2[i].second]);
                    num2[pos].second=num2[i].second;
                    num2[i].second=i;
                    
                }else
                {
                    flag=0;
                    break;
                }
            }
        }
        if(!flag)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
