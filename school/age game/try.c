#include<stdio.h>
int main ()
{
    int a;
    int q,w,e;
    char c;
    int age;
    printf("Please input your busiest day.\n");
    scanf("%d",&a);
    getchar();
    if(a<1||a>7)
    {
        printf("Invalid input.\n");
    }else
    {
        printf("Please input your gender.\n");
        scanf("%c",&c);
        if(c!='f'&&c!='m')
            printf("Invalid input.\n");
        else
        {
            printf("Please input your birthday.\n");
            scanf("%4d-%2d-%2d",&q,&w,&e);
            if(q%4!=0&&w==2&&e==29)
                printf("Invalid input.\n");
            else if(q%4!=0&&q%100==0&&q%400!=0&&w==2&&e==29)
                printf("Invalid input.\n");
            else
            {
                age=a*2;
                if(c=='m')
                {
                    age+=8;
                }else
                {
                    age+=4;
                }
                age*=50;
                if(w>=1&&w<=6)
                    age+=2002;
                else if(w>=7&&w<=12)
                    age+=3002;
                else
                    printf("Invalid input.\n");
                age-=q;
                age%=100;
                age+=10;
                printf("Your age is:%d\n",age);
            }
        }
    }
    return 0;
}
