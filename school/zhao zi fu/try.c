#include<Stdio.h>
#include<string.h>
int main ()
{
    printf("Input characters:");
    char s[60];
    int cnt=0;
    scanf("%s",s);
    int i;
    int len=strlen(s);
    for(i=0; i<len; i++)
    {
        if(s[i]=='k'||s[i]=='K')
            cnt++;
    }
    printf("k=%d",cnt);
    return 0;
}
