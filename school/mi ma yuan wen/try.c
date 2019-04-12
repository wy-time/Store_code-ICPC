#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main ()
{
    printf("请输入字符：\n");
    char s[100];
    scanf("%s",s);
    printf("密码是：%s\n",s);
    int len =strlen(s);
    int i;
    for(i=0;i<len;i++)
    {
        if(isupper(s[i]))
        {
            s[i]=27-(s[i]-'A'+1)+'A'-1;
        }else if(islower(s[i]))
        {
            s[i]=27-(s[i]-'a'+1)+'a'-1;
        }
    }
    printf("原文是：%s",s);
    return 0;
}
