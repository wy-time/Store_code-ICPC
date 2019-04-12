#include <iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    //std::ios::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int y,m,d;
        int r=0;
        int i;
        int ans[13]= {0,28,25,28,0,28,27,28,28,27,28,27,28};
        int ansy[30]= {302,302,303,302,0,302,303,302,302,302,303,302,302,302,0,302,302,302,303,302,302,302,303,302,0,302,303,303};
        scanf("%d-%d-%d",&y,&m,&d);
        if(y!=2018)
        {
            for(i=y+1-1990; i<28; i++)
            {
                r+=ansy[i];
            }
            if(ansy[y-1990]!=0)
            {
                for(i=m+1; i<13; i++)
                {
                    r+=ans[i];
                }
                if(d<4)
                {
                    r+=ans[m]-d+1;
                }
                else if(d>=4&&d<14)
                {
                    if(d==4)
                        r+=ans[m]-d+1;
                    else
                        r+=ans[m]-d+2;
                }
                else
                {
                    if(d==14)
                        r+=ans[m]-d+2;
                    else
                        r+=ans[m]-d+3;
                }
            }
            r+=81;
        }
        else
        {
            for(i=m+1; i<4; i++)
            {
                r+=ans[i];
            }
            if(d<4)
            {
                r+=ans[m]-d+1;
            }
            else if(d>=4&&d<14)
            {
                if(d==4)
                    r+=ans[m]-d+1;
                else
                    r+=ans[m]-d+2;
            }
            else
            {
                if(d==14)
                    r+=ans[m]-d+2;
                else
                    r+=ans[m]-d+3;
            }
        }
        r--;
        if(r<0)
            r=0;
        printf("%d\n",r);
    }
    return 0;
}
