#include <iostream>
#include<string>
#include<cctype>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int len=s.size();
    int i;
    bool first =true;
    int r=0;
    int l=0;
    for(i=len-1;i>=0;i--)
    {
        if(first&&isdigit(s[i]))
        {
            first=false;
            r=i;
        }
        if(!first&&!isdigit(s[i]))
        {
            if(s[i]=='-')
                l=i;
            else
                l=i+1;
            break;
        }
    }
    cout<<s.substr(l,r-l+1);
    return 0;
}
