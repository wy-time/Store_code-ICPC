#include <iostream>
#include<string>
using namespace std;
bool slove(string s);
int main()
{
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int len=s.size();
    if(len%2!=0)
    {
        cout<<len;
        return 0;
    }else
    {
        while(slove(s.substr(0,len))&&len%2==0)
        {
            len/=2;
        }
    }
    cout<<len;
    return 0;
}
bool slove(string s)
{
    int len=s.size();
    int i;
    for(i=0;i<len/2;i++)
    {
        if(s[i]!=s[len-1-i])
            return false;
    }
    return true;
}
