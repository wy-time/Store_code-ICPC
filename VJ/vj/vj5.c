#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void *b);
int main ()
{
    char a[6];
    int i=0;
    while (gets(a)!=NULL)
    {
        qsort(&a[0],3,sizeof(char),cmp);
        for(i=0;i<4;i++){
            printf("%c%c",a[i]," \n"[i==3]);
        }
    }F:\Desktop\question\VJ\vj\vj5.c
    return 0;
}
int cmp(const void*a,const void *b)
{
    return(((int)*(char*)a)-((int)*(char*)b));
}
