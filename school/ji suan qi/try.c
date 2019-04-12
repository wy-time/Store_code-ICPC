/*#include<stdio.h>
int main ()
{
    char p='Y';
    printf("Please enter the expression:\n");
    while(p=='Y'||p=='y')
    {

        double a,b,result;
        char c;
        scanf("%lf %c %lf",&a,&c,&b);
        getchar();
        switch (c)
        {
            case '+':
                result=a+b;
                break;
            case '-':
                result =a-b;
                break;
            case '*':
                result=a*b;
                break;
            case '/':
                result=a/b;
                break;
        }
        printf("%f\n",result);
        printf("Do you want to continue（Y/N or y/n）?");
        scanf("%c",&p);
    }
    return 0;
}*/
#include<stdio.h>
int main ()
{
    int safe =1;
    printf("Enter your expression:");
        double a,b,result;
        char c;
        scanf("%lf%c%lf",&a,&c,&b);
        getchar();
        switch (c)
        {
            case '+':
                result=a+b;
                break;
            case '-':
                result =a-b;
                break;
            case '*':
                result=a*b;
                break;
            case '/':
                result=a/b;
                break;
            default:
                safe=0;
        }
        if(b==0&&c=='/')
            printf("Division by zero.\n");
        else if(safe)
        {
            printf("%.2f%c%.2f=%.2f\n",a,c,b,result);
        }else
        {
            printf("Unknown operator.\n");
        }
        return 0;
    }


