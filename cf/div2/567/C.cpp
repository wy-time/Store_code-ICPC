#include <iostream>
#include <string> 
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
const int maxn=1005;
int num[maxn][maxn];
int same[maxn][maxn][2];
int pos[maxn];
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
    int n,m;
    cin>>n>>m;
    int i;
    wfor(i,0,n)
    {
        int j;
        string s;
        cin>>s;
        wfor(j,0,m)
        {
            num[i][j]=s[j];
        }
    }
    mfor(i,n-1,0)
    {
        int j;
        mfor(j,m-1,0)
        {
            if(num[i][j]==num[i][j+1])
                same[i][j][0]=same[i][j+1][0]+1;
            else
                same[i][j][0]=1;
            if(num[i][j]==num[i+1][j])
                same[i][j][1]=same[i+1][j][1]+1;
            else
                same[i][j][1]=1;
        }
    }
    int j;
    ll ans=0;
    int k;
    wfor(k,0,n)
    {
        int flag=1;
        wfor(j,0,m)
        {
            i=pos[j];
            if(i>=n-1)
                continue;
            flag=0;
            ll cnt=1e9;
            int t1=same[i][j][1];
            int t2,t3;
            if(i+t1<n)
            {
                t2=same[i+t1][j][1];
                if(t1==t2)
                {
                    if(i+t1+t2<n)
                    {
                        t3=same[i+t1+t2][j][1];
                        if(t2<=t3)
                        {
                            int end=i+t1+t2+min(t2,t3);
                            int tcnt=1e9;
                            wfor(i,i,end)
                            {
                                cnt=min(cnt,(ll)same[i][j][0]);
                                tcnt=min(tcnt,same[i][j-1][0]);
                            }
                            pos[j]+=t1;
                            if(tcnt<2)
                                ans+=(cnt*cnt+cnt)/2;
                        }else
                            pos[j]+=t1+t2-t3;
                    }else
                        pos[j]=n-1;
                }else
                {
                    if(t1>t2)
                        pos[j]+=t1-t2;
                    else
                        pos[j]+=t1;
                }
            }else
                pos[j]=n-1;
        }
        if(flag==1)
            break;
    }
    cout<<ans<<endl;
    return 0;
}
