#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef struct
{
    char s[500];
    long long x;
    long long y;
    long long id;
}people;
long long cmp (people a,people b);
int main()
{
    long long t1,t2;
    while(scanf("%lld",&t1)!=EOF)
    {
        people a[2000];
        long long i,j;
        for(i=0;i<t1;i++)
        {
            scanf("%s (%lld,%lld) %lld",a[i].s,&a[i].x,&a[i].y,&a[i].id);
        }
        sort(a,a+t1,cmp);
        scanf("%lld",&t2);
        for(j=0;j<t2;j++)
        {
            long long id1;
            char c[10];
            long long step=0;
            scanf("%lld %s",&id1,c);
            long long len =strlen(c);
            if(len==1)
            {
                scanf("%lld",&step);
                for(i=0;i<t1;i++)
                {
                    if(a[i].id==id1)
                    {
                        if(c[0]=='N')
                        {
                            a[i].y+=step;
                        }else if(c[0]=='S')
                        {
                            a[i].y-=step;
                        }else if(c[0]=='E')
                        {
                            a[i].x+=step;
                        }else if(c[0]=='W')
                        {
                            a[i].x-=step;
                        }
                    }
                }
            }
        }
        for(i=0;i<t1;i++)
        {
            printf("%s (%lld,%lld) %03lld\n",a[i].s,a[i].x,a[i].y,a[i].id);
        }
    }
    return 0;
}
long long cmp (people a,people b)
{
    return a.id<b.id;
}
