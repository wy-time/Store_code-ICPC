#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    int n;
    char s[60];
    cin>>n>>s;
    int i;
    int len=strlen(s);
    for(i=0;i<len;i++)
    {
        s[i]=((s[i]-'a'+n)%26)+'a';
    }
    cout<<s<<endl;
    return 0;
}
