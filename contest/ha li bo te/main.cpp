#include <iostream>
#include<cstdio>
#include<ctype.h>
#include<cstring>
using namespace std;
char s[2000];
int main()
{
    int k,b;
    while(cin>>k>>b)
    {
        getchar();
        gets(s);
        int i;
        int len =strlen(s);
        for(i=0;i<len;i++)
        if(isalpha(s[i]))
        {
            if(s[i]<'a')
            {
                s[i]=(k*(s[i]-'A')+b)%26+'A';
            }else
            {
                s[i]=(k*(s[i]-'a')+b)%26+'a';
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
