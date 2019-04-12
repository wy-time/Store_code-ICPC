#include <iostream>
#include<string>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int i;
    for(i=s.size()-1;i>=0;i--)
    {
        cout<<s[i];
    }
    for(i=t.size()-1;i>=0;i--)
    {
        cout<<t[i];
    }
    cout<<endl;
    return 0;
}
