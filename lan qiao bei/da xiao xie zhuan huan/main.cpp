#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    char s[25];
    cin>>s;
    int i;
    int len=strlen(s);
    char temp='a'-'A';
    for(i=0;i<len;i++)
    {
        if(s[i]<'a')
        {
            s[i]+=temp;
        }else
        {
            s[i]-=temp;
        }
    }
    cout<<s;
    return 0;
}
