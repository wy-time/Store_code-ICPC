#include<stdio.h>
int main ()
{
    char  month [12][20]= {"January","Februar","March","April","May","June","July","August","September","October","November","December"};
    int y,m,d;
    printf("Enter date (mm/dd/yy):");
    scanf("%d/%d/%d",&m,&d,&y);
    printf("Dated this %02d",d);
    switch(d)
    {
        case 1:
            printf("st day of ");
            break;
        case 2:
            printf("nd day of ");
            break;
        case 3:
            printf("rd day of ");
            break;
        default:
            printf("th day of ");
    }
    printf("%s",month[m-1]);
    printf(", 19%.2d.\n",y);
    return 0;
}
