#include<stdio.h>
int IsPerfect(int m);
main ()
{
    int num1;
    printf("Input m:\n");
    scanf("%d",&num1);
    if(IsPerfect(num1))
    {
        printf("%d is a perfect number\n",num1);
    }
    else
    {
        printf("%d is not a perfect number\n",num1);
    }
}
int IsPerfect(int m)
{
    int sum=0,j;
    for(j=1; j<m; j++)
    {
        if(m%j==0)
        {
            sum+=j;
        }
    }
    if(sum==m)
    {
        return 1;
    }
    else
        return 0;
}
