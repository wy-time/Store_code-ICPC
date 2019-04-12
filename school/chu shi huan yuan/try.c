#include<stdio.h>
int main ()
{
    int i,j;
    int t;
    int  cnt =0;
    for(i=10000000;i<100000000;i++)
    {
        for(j=100;j<1000;j++)
        {
            t=i/10000;
            if(t%j<10||t%j>100||t/j*j<1000)
                continue;
            else
            {
                t%=j;
                t=t*10+i/1000%10;
                if(t/j!=7||t%j<100||t%j>999)
                    continue;
                else
                {
                    t%=j;
                    t=t*10+i/100%10;
                    if(t%j>100||t%j<10)
                        continue;
                    else
                    {
                        t%=j;
                        t=t*10+i/10%10;
                        if(t%j<100||t/j!=0)
                            continue;
                        else
                        {
                            t%=j;
                            t=t*10+i%10;
                            if(t%j!=0||i/j>99999)
                                continue;
                            else
                            {
                                cnt ++;
                                printf("No%2d:%d/%d=%d\n",cnt,i,j,i/j);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
