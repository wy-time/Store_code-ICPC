#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main ()
{
    unsigned char a[201];
    int i;
    scanf("%s",a);
    int len= strlen(a);
    for(i=0;i<len;i++)
    {
        if(a[i]<0)
        {
            pintf("%x",a[i]-4294967040);//ffffff00
        }
        printf("%x ",a[i]);
    }
    return 0;
}
