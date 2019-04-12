#include <iostream>
#include<string>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int m;string s;
    cin>>m>>s;
    int i;
    int cnt=s.size()-1;
    bool first=true;
    for(i=0;i<s.size();i++)
    {
        if(s[i]!='0')
        {
            if(first)
            {
                first=false;
                cout<<s[i]<<"*"<<m<<"^"<<cnt;
            }else
                cout<<"+"<<s[i]<<"*"<<m<<"^"<<cnt;
        }
        cnt--;
    }
    return 0;
}
