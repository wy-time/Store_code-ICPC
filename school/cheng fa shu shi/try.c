#include<stdio.h>
#include<string.h>
int main ()
{
    char c[5]={"2357"};
    char p[100];
    int i,j,k,safe=1;
    int abc,de,x,y,z;
    for(i=100;i<999;i++)
    {
        for(j=10;j<99;j++)
        {
            safe =1;
            abc=i;
            de=j;
            x=abc*(de%10);
            y=abc*(de/10);
            z=abc*de;
            sprintf(p,"%d%d%d%d%d",abc,de,x,y,z);
            int len =strlen(p);
            for(k=0;k<len;k++)
            {
                if(strchr(c,p[k])==NULL)
                {
                    safe=0;
                    break;
                }
            }
            if(safe)
            {
                printf("%5d\n*%4d\n-----\n%5d\n%4d\n-----\n%5d\n",abc,de,x,y,z);
            }
        }

    }
    return 0;
}
