#include <math.h>
#include<stdio.h>
int isprime(int m);
main()
{
    int n,flag;
    printf("Input n:");
    scanf("%d", &n);
    flag=isprime(n);
    if(flag)
        printf("Yes!\n");
    else
        printf("No!\n");
}
/* 函数名：  isprime
函数功能：判断m是否为素数
入口参数：整型数m
返回值：  返回值为1时，表示m是素数；
返回值为0时，表示m不是素数 */
int isprime(int m)
{
    int i;
    if(m==1)
        return 0;  /*1不是素数，所以返回0值*/
    for(i=2; i<=sqrt(m); i++)
    {
    if(m%i==0)  return 0;
    }
    return 1;
}
