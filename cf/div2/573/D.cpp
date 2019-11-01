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
    int cnt3=0;
    wfor(i,0,n)
    {
        cin>>num[i];
        if(num[i]==0)
           cnt3+=1; 
    }
    sort(num,num+n);
    ll ans=0;
    int temp=1;
    int cnt=0;
    int cnt2=0;
    int flag=0;
    wfor(i,1,n)
    {
        if(num[i]==num[i-1])
        {
            temp++;
            if(i>1)
                if(num[i]-1==num[i-2])
                    flag=1;
        }else
        {
            if(temp>=2)
                cnt2++;
            temp=1;
        }
        cnt=max(cnt,temp);
    }
    if(temp>=2)
        cnt2++;
    wfor(i,0,n)
    {
        ans+=num[i]-i;
    }
    if(cnt<3&&cnt2<2&&cnt3<2&&!flag)
    {
        if(ans%2==0)
            cout<<"cslnb"<<endl;
        else
            cout<<"sjfnb"<<endl;
    }else
        cout<<"cslnb"<<endl;
    return 0;
}
