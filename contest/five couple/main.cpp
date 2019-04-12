#include<iostream>
#include<cstdio>
using namespace std;
int boy[100005];
inline int read(){
    int x=0; char ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
    return x;
}
int main ()
{
    register int n;
    //scanf("%d",&n);
    n=read();
    register int i;
    for(i=0;i<n;i++)
    {
        boy[i]=read();
    }
    register int m;
    m=read();
    while(m--)
    {
        register int l,r,b;
        long long maxx=-300;
        b=read();
        l=read();
        r=read();
        for(i=l-1;i<r;i++)
        {
            long long t=b^boy[i];
            maxx=max(maxx,t);
        }
        printf("%lld\n",maxx);
    }
    return 0;
}
