#include <iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    char c=s[0];
    int i=0;
    int len =s.size();
    for(i=0;i<len;i++)
    {
        if(s[i]==c)
        {
            s.erase(i,1);
            i--;
        }
    }
    if(s.size()!=0)
    {
        cout<<"NO"<<endl;
    }else
    {
        cout<<"YES"<<endl;
    }
    return 0;
}
