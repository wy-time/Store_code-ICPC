#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;
int a[500];
int b[500];
int c[1000];
void pp(int mode);
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    a[0]=1;
    b[0]=2;
    register int i;
    int wei=1;
    wei=n*log10(2.0)+1;
    int cnt=0;
    while(n)
    {
        if(n&1)
            pp(0);
        pp(1);
        n>>=1;
    }
    a[0]-=1;
    for(i=0;i<500&&a[i]<0;i++)
    {
        a[i]+=10;
        a[i+1]-=1;
    }
    cout<<wei;
    cnt=0;
    if(wei<500)
    {
        for(i=0;i<500-wei;i++)
        {
            if(cnt%50==0)
                cout<<endl;
            cout<<0;
            cnt++;
        }
        for(i=wei-1;i>=0;i--)
        {
            if(cnt%50==0)
                cout<<endl;
            cout<<a[i];
            cnt++;
        }
    }else
    {
        for(i=499;i>=0;i--)
        {
            if(cnt%50==0)
                cout<<endl;
            cout<<a[i];
            cnt++;
        }
    }
    return 0;
}
void pp(int mode)
{
    int i,j,k;
    int cnt=0;
    if(mode==0)
    {
        for(k=0;k<500;k++)
        {
            for(i=0;i<500;i++)
            {
                c[i+k]+=a[i]*b[k];
            }
            for(j=0;j<500||c[j]!=0;j++)
            {
                if(c[j]>=10)
                {
                    cnt=c[j]/10;
                    c[j]%=10;
                    c[j+1]+=cnt;
                }
            }
        }
        memcpy(a,c,sizeof(int)*500);
        memset(c,0,sizeof(c));
    }else
    {
        for(k=0;k<500;k++)
        {
            for(i=0;i<500;i++)
            {
                c[i+k]+=b[i]*b[k];
            }
            for(j=0;j<500||c[j]!=0;j++)
            {
                if(c[j]>=10)
                {
                    cnt=c[j]/10;
                    c[j]%=10;
                    c[j+1]+=cnt;
                }
            }
        }
        memcpy(b,c,sizeof(int)*500);
        memset(c,0,sizeof(c));
    }
}
