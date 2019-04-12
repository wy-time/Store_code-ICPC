#include<stdio.h>
#include<string.h>
int main ()
{
    char s[200];
    int i;
    printf("Enter a string to delete vowels\n");
    gets(s);
    int len =strlen(s);
    printf("String after deleting vowels: ");
    for(i=0;i<len;i++)
    {
        if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='a'&&s[i]!='u'&&s[i]!='A'&&s[i]!='E'&&s[i]!='I'&&s[i]!='O'&&s[i]!='U')
        {
            printf("%c",s[i]);
        }
    }
    printf("\n");
    return 0;
}
