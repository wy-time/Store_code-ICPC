#include<ctype.h>
#include<cstring>
#include<cstdio>
#include <iostream>
using namespace std;
char s[200000];
int main()
{
    while(gets(s)!=NULL)
    {
        int len =strlen(s);
        int i;
        int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
        for(i=0; i<len; i++)
        {
            if(isalpha(s[i]))
            {
                cnt1++;
            }
            else if(isdigit(s[i]))
                cnt2++;
            else if(isspace(s[i]))
                cnt3++;
            else
                cnt4++;
        }
        cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<cnt4<<endl;
    }
    return 0;
}
