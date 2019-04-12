#include<stdio.h>
#include<math.h>
int isprime (int n);
int main ()
{
    int x,y,i,p;
    scanf("%d %d",&x,&y);
    while(x!=0||y!=0)
    {
        p=1;
        for(i=x;i<=y;i++)
        {
            if(isprime(i*i+i+41)==0)
            {
                p=0;
                break;
            }
        }
        if(p)
        {
            printf("OK\n");
        }
        else
        {
            printf("Sorry\n");
        }
        scanf("%d %d",&x,&y);
    }
    return 0;
}
int isprime (int n)
{
    int i=0,p=1;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            p=0;
            break;
        }
    }
    return p;
}
