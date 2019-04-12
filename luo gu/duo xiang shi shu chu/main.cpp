#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[105];
    int i;
    for(i=n;i>=0;i--)
    {
        scanf("%d",&a[i]);
    }
    i=n;
    while(a[i]==0)
    {
        i--;
    }
    if(a[i]==1)
        printf("x^%d",i);
    else if(a[i]==-1)
        printf("-x^%d",i);
    else
        printf("%dx^%d",a[i],i);
    i--;
    for(;i>=2;i--)
    {
        if(a[i]!=1&&a[i]!=-1&&a[i]!=0)
            printf("%+dx^%d",a[i],i);
        else if(a[i]==0)
            continue;
        else if(a[i]==1)
            printf("+x^%d",i);
        else if(a[i]==-1)
            printf("-x^%d",i);
    }
    if(a[i]==-1)
    {
        printf("-x");
    }else if(a[i]==1)
    {
        printf("+x");
    }else if(a[i]!=0)
    {
        printf("%+dx",a[i]);
    }
    i--;
    if(a[i]!=0)
        printf("%+d",a[i]);
    return 0;
}
