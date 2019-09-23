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
const int maxn=2e5+5;
pair<int,int>num[maxn];
int cha[maxn];
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
        cin>>num[i].first;
        num[i].second=i+1;
    }
    sort(num,num+n);
    wfor(i,0,n-1)
    {
        cha[i]=num[i+1].first-num[i].first;
    }
    if(n==2)
    {
        cout<<1<<endl;
    }else
    {
        int flag=0;
        int ans=0;
        wfor(i,1,n-1)
        {
            if((cha[i]==cha[i-1]&&i+1>=n-1)||(i+1<n-1&&cha[i]==cha[i-1]&&cha[i]==cha[i+1]))
                continue;
            else
            {
                if(flag==1)
                {
                    flag=2;
                    break;
                }
                if(i==1)
                {
                    if(cha[i]==cha[i+1])
                    {
                        flag=1;
                        ans=num[i-1].second;
                    }
                    else if(cha[i]+cha[i-1]==cha[i+1])
                    {
                        flag=1;
                        ans=num[i].second;
                        cha[i]=cha[i+1];
                        cha[i-1]=cha[i+1];
                    }else if(cha[i]+cha[i+1]==cha[i-1])
                    {
                        flag=1;
                        ans=num[i+1].second;;
                        cha[i]=cha[i-1];
                        cha[i+1]=cha[i-1];
                    }else if(i==n-2)
                    {
                        ans=num[n-1].second;
                        flag=1;
                    }
                    else if(cha[i]!=cha[i-1])
                    {
                        flag=2;
                        break;
                    }
                }else
                {
                    if(cha[i+1]+cha[i]==cha[i-1])
                    {
                        flag=1;
                        ans=num[i+1].second;
                        cha[i]=cha[i-1];
                        cha[i+1]=cha[i-1];
                    }else if(i==n-3&&cha[i-1]==cha[i])
                    {
                        flag=1;
                        cha[i+1]=cha[i];
                        ans=num[n-1].second;
                    }
                    else if(cha[i]!=cha[i-1])
                    {
                        flag=2;
                        break;
                    }
                }
            }
        }
        if(flag==0)
            cout<<num[0].second<<endl;
        else if(flag==1)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
