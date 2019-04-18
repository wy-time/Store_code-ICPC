#include <iostream>
#include <algorithm> 
#include <set> 
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
int num[1005];
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
    set<int>v;
    wfor(i,0,n)
    {
        cin>>num[i];
    }
    sort(num,num+n);
    int last=num[0];
    int ans=-1;
    int flag=1;
    int cnt=0;
    wfor(i,1,n)
    {
        int temp=num[i]-last;
        if(temp!=0)
        {
           if(ans==-1)
               ans=temp;
           else if(ans==temp)
               ans=temp;
           else
           {
               flag=0;
               break;
           }
           cnt++;
        }
        last=num[i];
    }
    if(flag&&ans==-1)
        ans=0;
    if(flag)
    {
        if(cnt>=2)
            cout<<ans<<endl;
        else
        {
            if(ans%2==0)
                cout<<ans/2<<endl;
            else
                cout<<ans<<endl;
        }
    }
    else
        cout<<-1<<endl;
    return 0;
}
