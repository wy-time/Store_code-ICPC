#include <iostream>
#include<string.h>
#include<cstdio>
#include<ctype.h>
using namespace std;
int main()
{
    int n,i,cnt;
    scanf("%d",&n);
    getchar();
    char s[1000];
    while(n--)
    {
        cnt=0;
        gets(s);
        int len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(isdigit(s[i]))
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
