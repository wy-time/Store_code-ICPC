#include <iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    string s,s1;
    int t;
    cin >>t;
    while(t--)
    {
        cin>>s;
        s1=s;
        reverse(s.begin(),s.end());
        if(s1==s)
        {
            cout<<"yes"<<endl;
        }else
        {
            cout<<"no"<<endl;
        }
    }
    return 0;
}
