#include<stdio.h>
int main ()
{
    printf("Enter 5 integers: ");
    int a[5];
    int x;
    int idx=-1;
    int i;
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter x: ");
    scanf("%d",&x);
    for(i=0;i<5;i++)
    {
        if(x==a[i])
        {
            idx=i;
            break;
        }
    }
    if(idx>0)
    {
        printf("Index is %d\n",idx);
    }else
    {
        printf("Not Found");
    }
    return 0;
}
