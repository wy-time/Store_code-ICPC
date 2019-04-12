#include<stdio.h>
int main()
{
    printf("Please enter year,month:");
    int y, m;
    int safe = 1;
    safe=0;
    scanf("%d,%d",&y,&m);
    if(y % 4 == 0 && y % 100 != 0)
    {
        safe = 1;
    }
    else if( y % 400 == 0)
        safe=1;
    if(safe)
        printf("%d is leap year\n",y);
    else
        printf("%d is not leap year\n",y);//The season is spring/summer/autumn/winter
    switch(m)
    {
        case 12:
            printf("The season is winter\n");
            printf("The number of days of this month is %d\n",31);
            break;
        case 11:
            printf("The season is autumn\n");
            printf("The number of days of this month is %d\n",30);
            break;
        case 10:
            printf("The season is autumn\n");
            printf("The number of days of this month is %d\n",31);
            break;
        case 9:
            printf("The season is autumn\n");
            printf("The number of days of this month is %d\n",30);
            break;
        case 8:
            printf("The season is summer\n");
            printf("The number of days of this month is %d\n",31);
            break;
        case 7:
            printf("The season is summer\n");
            printf("The number of days of this month is %d\n",31);
            break;
        case 6:
            printf("The season is summer\n");
            printf("The number of days of this month is %d\n",30);
            break;
        case 5:
            printf("The season is spring\n");
            printf("The number of days of this month is %d\n",31);
            break;
        case 4:
            printf("The season is spring\n");
            printf("The number of days of this month is %d\n",30);
            break;
        case 3:
            printf("The season is spring\n");
            printf("The number of days of this month is %d\n",31);
            break;
        case 2:
            if(safe)
            {
                printf("The season is winter\n");
                printf("The number of days of this month is %d\n",29);
                break;
            }
            else
            {
                printf("The season is winter\n");
                printf("The number of days of this month is %d\n",28);
                break;
            }
        case 1:
            printf("The season is winter\n");
            printf("The number of days of this month is %d\n",31);
            break;
    }
    return 0;
}
