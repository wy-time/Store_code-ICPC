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
int sum[2][4][2][120];
void slove()
{
    memset(sum,0,sizeof(sum));
    int i,j,k;
    wfor(i,0,2)
    {
        wfor(j,0,4)
        {
            wfor(k,0,2)
            {
                int a,b,c;
                wfor(a,0,i+1)
                    wfor(b,0,j+1)
                        wfor(c,0,k+1)
                            sum[i][j][k][a*10+b*20+c*50]=1;
            }
        }
    }
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
    while(t--)
    {
        slove();
        int num[105];
        int n;
        cin>>n;
        int i,j,k;
        int no=0;
        wfor(i,0,n)
        {
            cin>>num[i];
            if(num[i]%10!=0)
                no=1;
        }
        if(no==1)
        {
            cout<<-1<<endl;
            continue;
        }
        ll ans=1e9;
        wfor(i,0,2)
        {
            wfor(j,0,4)
            {
                wfor(k,0,2)
                {
                    int p;
                    int cnt=0;
                    int flag=1;
                    wfor(p,0,n)
                    {
                        if(sum[i][j][k][num[p]%100]!=1&&(num[p]<=110&&sum[i][j][k][num[p]]!=1))
                        {
                            flag=0;
                            break;
                        }else
                        {
                            int fix=0;
                            if(num[p]%100==0&&sum[i][j][k][100]==1)
                                fix++;
                            if(num[p]%110==0&&sum[i][j][k][110]==1)
                                fix++;
                            cnt=max(cnt,num[p]/100-fix);
                        }
                    }
                    if(flag)
                    {
                        ans=min(ans,(ll)i+j+k+cnt);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
