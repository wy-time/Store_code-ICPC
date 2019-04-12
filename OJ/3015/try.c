#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main ()
{
    int n,m;
    scanf("%d",&n);
    char *s=(char*)malloc(sizeof(char)*n);
    char *s2=(char*)malloc(sizeof(char)*n);
    getchar();
    gets(s);
    scanf("%d",&m);
    strcpy(s2,&s[m-1]);
    printf("%s",s2);
    return 0;
}
