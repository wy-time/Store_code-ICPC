#include<stdio.h>
#include<string.h>
int main ()
{
    int i = 0;
    char s[1000];
    gets(s);
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    int len = strlen(s);
    for(i = 0; i < len; i++)
    {
        if(isalpha(s[i]))
        {
            cnt1++;
        }
        else if(isdigit(s[i]))
        {
            cnt2++;
        }else if(s[i]==' '){
            cnt3++;
        }else {
            cnt4++;
        }
    }
    printf("%d %d %d %d\n",cnt1,cnt2,cnt3,cnt4);
    return 0;
}
