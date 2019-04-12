#include<string>
#include<algorithm>
#include <iostream>
using namespace std;
int main()
{
    string s2,s1;
    cin>>s1>>s2;
    if(s1.size()!=s2.size())
    {
        cout<<1<<endl;
    }else if(s1==s2)
    {
        cout<<2<<endl;
    }else
    {
        transform(s1.begin(),s1.end(),s1.begin(),::tolower);
        transform(s2.begin(),s2.end(),s2.begin(),::tolower);
        if(s1==s2)
        {
            cout<<3<<endl;
        }else
        {
            cout<<4<<endl;
        }
    }
    return 0;
}
