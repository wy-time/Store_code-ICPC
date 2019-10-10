#include <iostream>
#include <cmath> 
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
pair<int,int>num[maxn];
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
    int cnt=0;
    wfor(i,0,n)
    {
        cin>>num[i].first;
        num[i].second=i;
        if(num[i].first>=0)
            cnt++;
    }
    sort(num,num+n);
    if(cnt==0&&n%2!=0)
    {
        num[0].first=num[0].first*-1-1;
    }else
    {
        if(n%2==0)
        {
            wfor(i,0,n)
            {
                if(num[i].first>=0)
                {
                    num[i].first=num[i].first*-1-1;
                }
            }
        }else
        {
            wfor(i,0,n-1)
            {
                if(num[i].first>=0)
                {
                    num[i].first=num[i].first*-1-1;
                }
            }
            sort(num,num+n);
            if(abs(num[0].first)>num[n-1].first)
            {
                num[0].first=num[0].first*-1-1;
                num[n-1].first=num[n-1].first*-1-1;
            }
        }
    }
    wfor(i,0,n)
    {
        ans[num[i].second]=num[i].first;
    }
    wfor(i,0,n)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
