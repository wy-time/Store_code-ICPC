#include <iostream>
#include<algorithm>
#include<stdlib.h>
#include<cstdio>
using namespace std;
int main()
{
    int n,i;
    double sum;
    int *a;
    while(scanf("%d",&n)!=EOF)
    {
        sum =0;
        a=(int*)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        a[0]=a[n-1]=0;
        for(i=0;i<n;i++)
        {
            sum+=a[i];
        }
        printf("%.2f\n",sum/(n-2));
    }
    return 0;
}
