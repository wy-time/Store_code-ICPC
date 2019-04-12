#include <iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
    int n,m,i;
    double sum,t;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        sum=0;
        t=n;
        for(i=m;i>0;i--)
        {
            sum+=t;
            t=sqrt(t);
        }
        printf("%.2f\n",sum);
    }
    return 0;
}
