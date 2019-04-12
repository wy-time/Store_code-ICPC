#include<stdio.h>
int main()
{
    int i, j, a, n, s[31000]={0};
    while(scanf("%d", &n)!=EOF)
    {
        j=0;
        while(n--)
        {
            scanf("%d", &a);
            for(i=0; i<j; i++)
                if(s[i]>=a)
                {
                    s[i]=a;
                    break;
                }
            if(i==j) s[j++]=a;
        }
        printf("%d\n", j);
    }
    return 0;

}
