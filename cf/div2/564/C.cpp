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
const int maxn=2e5+5;
int hend[maxn];
int table[maxn];
int is[maxn];
int pos[maxn];
int slove(int n)
{
    int i=0;
    int ans=0;
    int point=0;
    if(!is[i+1])
    {
        wfor(i,0,n)
        {
            ans++;
            is[table[i]]=1;
            if(table[i]==1)
                break;
        }
        point=i+1;
    }
    wfor(i,1,n)
    {
        if(is[i+1]||pos[i+1]<=point+i-1)
            continue;
        else
        {
            while(table[point+i-1]!=i+1&&is[i+1]==0)
            {
                ans++;
                is[table[point]]=1;
                point++;
            }
        }
    }
    return ans+n;
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
    int n;
    cin>>n;
    int i;
    wfor(i,0,n)
    {
        cin>>hend[i];
        is[hend[i]]=1;
    }
    int flag=1;
    int one=0;
    wfor(i,0,n)
    {
        cin>>table[i];
        if(table[i]!=i+1)
            flag=0;
        if(table[i]==1)
            one=i;
        pos[table[i]]=i;
    }
    if(flag!=1)
    {
        int ans=0;
        int flag2=1;
        wfor(i,one+1,n)
        {
            if(table[i]!=1+i-one)
            {
                flag2=0;
                break;
            }
        }
        if(!flag2)
        {
            ans=slove(n);
        }else
        {
            flag2=1;
            int now=n-one;
            if(!is[now+1])
            {
                flag2=0;
            }else
            {
                wfor(i,now+1,n)
                {
                    if(is[i+1]||pos[i+1]<=i-now-1)
                        continue;
                    else
                    {
                        flag2=0;
                        break;
                    }
                }
            }
            if(flag2)
                ans=n-now;
            else
                ans=slove(n);
        }
        cout<<ans<<endl;
    }else
        cout<<0<<endl;
    return 0;
}
