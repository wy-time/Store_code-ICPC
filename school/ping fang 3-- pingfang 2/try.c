#include<stdio.h>
int main ()
{
    int i,j,k;
    int x;
    int cnt=0;
    int t1,t2;
    printf("The possible perfect squares combinations are:\n");
    for(i=20; i*i<1000; i++)
    {
        for(j=10; j*j<1000; j++)
        {
            t1=i*i;
            t2=j*j;
            x=t1/100;
            x*=10;
            x+=t2/100;
            cnt=0;
            for(k=0; k<=9; k++)
            {
                if(x==k*k)
                {
                    if(cnt==0)
                    {
                        x=t1%100/10;
                        x*=10;
                        x+=t2%100/10;
                        k=-1;
                        cnt++;
                    }else if(cnt==1)
                    {
                        x=t1%10;
                        x*=10;
                        x+=t2%10;
                        k=-1;
                        cnt++;
                    }else
                    {
                        printf("%d and %d\n",t1,t2);
                    }
                }
            }
        }
    }
    return 0;
}
