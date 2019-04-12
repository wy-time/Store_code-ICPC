#include <iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    char c;
    getline(cin,s);
    cin>>c;
    int i;
    int len =s.size();
    for(i=0;i<len;i++)
    {
        if(s[i]!=c)
            cout<<s[i];
    }
    return 0;
}
