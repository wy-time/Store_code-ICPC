#include<stdio.h>
int main ()
{
    int i=0,t,a;
    int cnt=1;
    for(i=1; cnt!=5; i++)
    {
        cnt=1;
        t=i;
        if(t%5!=1)
            continue;
        else
        {
            do
            {
                a=cnt;
                t-=1;
                t-=t/5;
                if(t%5==1)
                    cnt++;
                if(a==cnt||cnt==5)
                    break;
            }
            while(1);
            if(cnt==5)
            {
                printf("y = %d\n",i);
                break;
            }
        }
    }
    return 0;
}
