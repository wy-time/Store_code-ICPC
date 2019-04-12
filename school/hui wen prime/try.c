#include<stdio.h>
#include<math.h>
#include<string.h>
int isprime(int n);
int main ()
{
    int a,b,i,t,j;
    scanf("%d %d",&a,&b);
    for(i=a;i<=b;i++)
    {
        if(isprime(i)==1)
        {
            char c1[11]={'0'},c2[11]={'0'};
            t=i;
            for(j=0;t!=0;j++)
            {
                c1[j]=(t%10)+'0';
                t/=10;
            }
            int len =strlen(c1);
            int q=len;
            for(j=0;j<len;j++)
            {

                c2[q-1]=c1[j];
                q--;
            }
            if(strcmp(c1,c2)==0)
            {
                printf("%d\n",i);
            }
        }
    }
    return 0;
}
int isprime(int n)
{
    int j=1,i=0;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            j=0;
            break;
        }
    }
    return j;
}
