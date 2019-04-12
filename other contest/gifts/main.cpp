#include <iostream>
#include<algorithm>
#include<cstring>
#include <cstdio>
int a[2000000];
using namespace std;
int main()
{
    int n=0;
    int i;
    int cnt=0;
    int up,down;
    while ((scanf("%d",&n)!=EOF)&&n)
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        if(a[0]!=a[1])
        {
            printf("%d\n",a[i]);
        }
        else
        {

            for(i=1; i<n; i++)
            {
                down=i;
                up=i+((n-(10*cnt))>10?10:n-1);
                cnt++;
                if(a[i]!=a[i+1]&&a[i]!=a[i-1])
                {
                    printf("%d\n",a[i]);
                    break;
                }
                else
                {
                    if(a[down]==a[up])
                    {
                        down=up;
                        up=down+((n-(10*cnt))>10?10:n-1);
                        cnt++;
                    }
                    else
                    {
                        while(a[down]!=a[up])
                        {
                            up=(up+down)/2;
                        }
                        if(a[up]==a[up+1])
                        {
                            i=up+1;
                        }
                        else
                            i=up;
                    }
                }
            }
        }
        memset(a,0,(n+1)*sizeof(int));
    }
    return 0;
}
