#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[200005];
int main()
{
    //std::ios::sync_with_stdio(false);
    char s[7]="aeiouy";
    while(gets(a)!=NULL)
    {
        int len=strlen(a);
        int i;
        for(i=0;i<len;i++)
        {
            a[i]=tolower(a[i]);
            int pos=upper_bound(s,s+6,a[i])-s;
            a[i]=s[pos-1];
        }
        printf("%s\n",a);
    }
    return 0;
}
