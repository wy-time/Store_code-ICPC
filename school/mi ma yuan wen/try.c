#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main ()
{
    printf("�������ַ���\n");
    char s[100];
    scanf("%s",s);
    printf("�����ǣ�%s\n",s);
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
    printf("ԭ���ǣ�%s",s);
    return 0;
}
