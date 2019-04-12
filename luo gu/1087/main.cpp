#include <iostream>
#include<string>
using namespace std;
void slove(string s);
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    cin>>s;
    slove(s);
    return 0;
}
void slove(string s)
{
    if(s.size()!=1)
    {
        slove(s.substr(0,s.size()/2));
        slove(s.substr(s.size()/2));
        if(s.find('0')!=::string::npos)
        {
            if(s.find('1')!=::string::npos)
            {
                cout<<"F";
            }else
            {
                cout<<"B";
            }
        }else if(s.find('1')!=::string::npos)
            cout<<"I";
    }else
    {
        if(s.find('1')!=::string::npos)
            cout<<"I";
        else
            cout<<"B";
    }
}
