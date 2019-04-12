#include <iostream>
#include <cstdio>
#include <algorithm>
long long int a,b,c,d,e,sum;
using namespace std;
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%lld",&a);
    while(a--)
    {sum=0;
        scanf("%lld",&b);
        if(b<3)
        {
            printf("-1\n");
        }
        else
        {
        int p=b%3;
        if(p==0)
        {
           printf("%lld\n",(b/3)*(b/3)*(b/3));
        }
        else
        {
            if(b%4==0)
            {
                printf("%lld\n",(b/4)*(b/4)*(b/2));
            }
            else
                {
                printf("-1\n");

                }


        }
        }
    }
    return 0;
}
