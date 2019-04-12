#include <iostream>
#include<string.h>
#include<cstdio>
using namespace std;
int main()
{
    char s[30];
    gets (s);
    char c;
    cin>>c;
    int len =strlen(s);
    int i;
    for(i=0;i<len;i++)
    {
        if(s[i]!=c)
            cout<<s[i];
    }
    return 0;
}
