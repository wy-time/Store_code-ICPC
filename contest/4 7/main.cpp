#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    char s[100];
    cin>>s;
    int i;
    int len=strlen(s);
    int cnt1=0;
    int cnt2=0;
    for(i=0;i<len;i++)
    {
        if(s[i]=='4')
            cnt1++;
        else if(s[i]=='7')
            cnt2++;
    }
    if(cnt1!=0||cnt2!=0)
    {
        if(cnt1>=cnt2)
            cout<<4;
        else if(cnt1<cnt2)
            cout<<7;
    }else
        cout<<-1;
    return 0;
}
