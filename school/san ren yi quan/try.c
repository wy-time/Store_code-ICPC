#include<stdio.h>
struct jj{int a};
int main ()
{
    int a[13]={0};
    int j=13;
    int i=0;
    int cnt=0;
    printf("\n\n出圈成员及顺序：");
    for(i=0; j!=1; i++)
    {
        if(a[i]==0)
        {
            cnt++;
            if(cnt%3==0)
            {
                j--;
                a[i]=1;
                printf("%3d",i+1);
            }
        }

        if(i==12)
            i=-1;
    }
    for(i=0;i<13;i++)
    {
        if(a[i]==0)
        {
            printf("\n最后的成员是：%3d",i+1);
        }
    }
    return 0;
}
