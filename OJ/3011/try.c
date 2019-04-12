#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* min(char*a,char*b);
char* max(char*a,char*b);
int main ()
{
    char s1[100],s2[100],s3[100];
    char *a,*b,*c;
    a=(char*)malloc(sizeof(char)*100);
    b=(char*)malloc(sizeof(char)*100);
    c=(char*)malloc(sizeof(char)*100);
    gets(s1);
    gets(s2);
    gets(s3);
    a=min(s1,min(s2,s3));
    if(a==s1)
    {
        b=min(s2,s3);
        c=max(s2,s3);
    }else if(a==s2)
    {
        b=min(s1,s3);
        c=max(s1,s3);
    }else
    {
        b=min(s2,s1);
        c=max(s2,s1);
    }
    puts(a);
    puts(b);
    puts(c);
    return 0;
}
char* min(char*a,char*b)
{
    if(strcmp(a,b)<0)
    {
        return a;
    }else
    {
        return b;
    }
}
char* max(char*a,char*b)
{
    if(strcmp(a,b)>0)
    {
        return a;
    }else
    {
        return b;
    }
}
