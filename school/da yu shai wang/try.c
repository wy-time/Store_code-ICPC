#include<stdio.h>
int main()
{
    int y, m, d = 0;
    int safe = 1;
    int sum = 0;
    int i;
    printf("Enter year/month/day:");
    while(scanf("%d%d%d", &y, &m, &d) != EOF)
    {
        for(i=1990;i<y;i++)
        {
            if(i % 4 == 0 && i % 100 != 0)
            {
                sum+=366;
            }else if( i % 400 == 0)
                    sum+=366;
        }
        safe=1;
        if(y % 4 == 0 && y % 100 != 0)
        {
            safe = 0;
        }else if( y % 400 == 0)
                safe=0;

        switch(m)
        {
            case 12:
                sum += d;
            case 11:
                if(m != 11)
                    sum += 30;
                else
                    sum += d;
            case 10:
                if(m != 10)
                    sum += 31;
                else
                    sum += d;
            case 9:
                if(m != 9)
                    sum += 30;
                else
                    sum += d;
            case 8:
                if(m != 8)
                    sum += 31;
                else
                    sum += d;
            case 7:
                if(m != 7)
                    sum += 31;
                else
                    sum += d;
            case 6:
                if(m != 6)
                    sum += 30;
                else
                    sum += d;
            case 5:
                if(m != 5)
                    sum += 31;
                else
                    sum += d;
            case 4:
                if(m != 4)
                    sum += 30;
                else
                    sum += d;
            case 3:
                if(m != 3)
                    sum += 31;
                else
                    sum += d;
            case 2:
                if(m != 2)
                {
                    if(safe)
                        sum += 28;
                    else
                        sum += 29;
                }
                else
                    sum += d;
            case 1:
                if(m != 1)
                    sum += 31;
                else
                    sum += d;
        }
        if(sum%5==1||sum%5==2||sum%5==3)
            printf("He is fishing.\n");
        else
            printf("He is sleeping.\n");
    }
    return 0;
}
