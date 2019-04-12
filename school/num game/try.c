#include<stdio.h>
int wwy(int n);
int main ()
{
    int n;
    printf("Input a sum:");
    scanf("%d",&n);
    if(wwy(n)==0)
    {
        printf("The sum you calculated is wrong!\n");
    }
    return 0;
}
int wwy(int n)
{
    int i,j,k,sum=0;
    for(i=1; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            for(k=0; k<10; k++)
            {
                sum=0;
                sum+=(i*100+i*10*2+i*2);
                sum+=(k*2*100+k*10+k*2);
                sum+=(j*100*2+j*10*2+j);
                if (sum==n)
                {
                    printf("The number is %d\n",i*100+k*10+j);
                    return 1;
                }
            }
        }
    }
    return 0;
}
