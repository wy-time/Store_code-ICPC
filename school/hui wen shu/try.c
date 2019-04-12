#include<stdio.h>
int main ()
{
    printf("please enter a number optionaly:");
    long int a;
    scanf("%ld",&a);
    printf("The generation process of palindrome:\n");
    int i;
    int b[10];
    int flag=1;
    int cnt=0;
    long int t=a;
    while(flag)
    {
        flag =0;
        for(i=0;a!=0;i++)
        {
            b[i]=a%10;
            a/=10;
        }
        long int c=0;
        int max=i;
        for(i=0;i<max;i++)
        {
            c=c*10+b[i];
        }
        cnt++;
        printf("   [%d]: %ld+%ld=%ld\n",cnt,t,c,t+c);
        c+=t;
        t=c;
        for(i=0;c!=0;i++)
        {
            b[i]=c%10;
            c/=10;
        }
        max=i-1;
        for(i=0;i<(max+1)/2;i++)
        {
            if(b[i]!=b[max-i])
            {
                flag =1;
                a=t;
                break;
            }
        }
    }
    printf("Here we reached the aim at last !\n");
    return 0;
}
