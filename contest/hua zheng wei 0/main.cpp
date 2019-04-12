#include<cstring>
#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
    char s[200];
    while(cin>>s)
    {
        int sum=0;
        int len =strlen(s);
        int i;
        for(i=0;i<len;i++)
        {
            sum+=(s[i]-'0');
        }
        while(sum>=10)
        {
            sprintf(s,"%d",sum);
            len =strlen(s);
            sum=0;
            for(i=0;i<len;i++)
            {
                sum+=(s[i]-'0');
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
