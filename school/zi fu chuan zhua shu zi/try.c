#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main ()
{
    printf("请输入四个数字字符：");
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
        printf("你输入的数值+1后为%d\n",t+1);
    }else
    {
        printf("有非数字字符！");
    }
    return 0;
}
