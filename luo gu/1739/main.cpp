#include <iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    stack <char> ack;
    int i;
    bool right=true;
    int len =s.size();
    for(i=0;i<len;i++)
    {
        if(s[i]=='(')
            ack.push('(');
        else if(s[i]==')')
        {
            if(!ack.empty())
                ack.pop();
            else
                right=false;
        }
    }
    if(!ack.empty())
        right=false;
    if(right)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
