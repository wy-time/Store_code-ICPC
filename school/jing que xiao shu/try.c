#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char r[10000];
int main ()
{
    printf("please input a fraction (m/n))  (0< m< n<=100):");
    int a,b,i;
    r[0]='0';
    int safe=0;
    r[1]='.';
    scanf("%d/%d",&a,&b);
    int j=a;
    for(i=2; i<10000&&a!=0; i++)
    {
        a=a%b;
        a*=10;
        r[i]=(a/b)+'0';
    }
    int len =strlen(r);
    char*p1=(char*)malloc(sizeof(char)*len+1);
    char*p2=(char*)malloc(sizeof(char)*len+1);
    char*p3=(char*)malloc(sizeof(char)*len+1);
    char*p4=(char*)malloc(sizeof(char)*len+1);
    for(i=2; i<len; i++)
    {
        if((p1=strchr(r,r[i]))==NULL)
            continue;
        if((p2=strchr(p1+1,r[i]))==NULL)
            continue;
        *p2='\0';
        strcpy(p3,p1);
        *p2=r[i];
        if((p1=strchr(p2+1,r[i]))==NULL)
            continue;
        *p1='\0';
        strcpy(p4,p2);
        *p1=r[i];
        if(strcmp(p3,p4)==0)
        {
            len =strlen(p3);
            safe =1;
            break;
        }
    }
    int t=i;
    printf("%d/%d it's accuracy value is:0.",j,b);
    if(safe)
    {
        for(i=2; i<t+len; i++)
        {
            printf("%c",r[i]);
        }
        printf("\n\tand it is a infinite cyclic fraction from %d\n",t-1);
        printf("\tdigit to %d digit after decimal point.\n",t+len-2);
    }
    else
    {
        len =strlen(r);
        for(i=2;i<len;i++)
        {
            printf("%c",r[i]);
        }
    }
    free(p1),free(p2),free(p3),free(p4);
    return 0;
}
