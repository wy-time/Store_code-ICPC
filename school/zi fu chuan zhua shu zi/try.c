#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main ()
{
    printf("�������ĸ������ַ���");
    char s[5];
    int safe =1;
    scanf("%s",s);
    int i;
    for (i=0;i<4;i++)
    {
        if(!isdigit(s[i]))
        {
            safe =0;
            break;
        }
    }
    if(safe)
    {
        int t=atoi(s);
        printf("���������ֵ+1��Ϊ%d\n",t+1);
    }else
    {
        printf("�з������ַ���");
    }
    return 0;
}
