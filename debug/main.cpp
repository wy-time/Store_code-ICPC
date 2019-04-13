#include <iostream>
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
int main()
{
    //std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("/home/time/debug/debug/in","r",stdin);
    freopen("/home/time/debug/debug/out","w",stdout);
    #endif
    int n;
    cin>>n;
    int mou[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    while(n--)
    {
        int y,m,d,h,mi,s;
        scanf("%d-%d-%d %d:%d:%d",&y,&m,&d,&h,&mi,&s);
        int i;
        ll ans=0;
        wfor(i,y+1,2050)
        {
            if((i%4==0&&i%100!=0)||(i%400==0))
            {
                ans+=366;
            }else
                ans+=365;
        }
        if((y%4==0&&y%100!=0)||y%400==0)
        {
            if(m<2)
                ans++;
            wfor(i,m+1,13)
                ans+=mou[i];
            if(m==2)
                ans+=max(29-d-1,0);
            else
                ans+=max(mou[m]-d-1,0);
        }else
        {
            wfor(i,m+1,13)
                ans+=mou[i];
            ans+=max(mou[m]-d-1,0);
        }
        ans=ans%100*24%100*60%100*60%100;
        int temp=h*3600+mi*60+s;
        temp=24*3600-temp;
        ans+=temp;
        ans%=100;
        cout<<ans<<endl;
    }
    return 0;
}
