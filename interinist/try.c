#include <stdio.h>
int main(void)
{
    int a=0;
    scanf("%d",&a);//输入棱形的上叶行数
    for(int i=a-1; i>=0; i--)
    {
        for(int j=i ; j>0; j--)
        {
            printf(" ");
        }
        for(int k=((a*2-1)-i*2); k>0; k--)
        {
            printf("*");
        }
        printf("\n");
    }
    for(int i=a-2; i>=0; i--)
    {
        for(int j=(a-1)-i; j>0; j--)
        {
            printf(" ");
        }
        for(int k=i*2+1; k>0; k--)
        {
            printf("*");
        }
        printf("\n");
    }
}
