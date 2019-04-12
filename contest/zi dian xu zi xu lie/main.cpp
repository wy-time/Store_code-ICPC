#include <iostream>
#include<string>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int len=s.size();
    int i;
    for(i=1; i<len; i++)
    {
        while(s[i]>s[i-1]&&i>0)
        {
            s.erase(i-1,1);
            len=s.size();
            i--;
        }
    }
    cout<<s;
    return 0;
}
