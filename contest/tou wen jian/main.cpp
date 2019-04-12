#include <iostream>
#include<string>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    string ans[40]={"algorithm","bitset", "cctype", "cerrno", "clocale", "cmath", "complex", "cstdio", "cstdlib", "cstring", "ctime", "deque", "exception", "fstream", "functional", "limits", "list", "map", "iomanip", "ios", "iosfwd", "iostream", "istream", "ostream", "queue", "set", "sstream", "stack", "stdexcept", "streambuf", "string", "utility", "vector", "cwchar", "cwctype"};
    while(t--)
    {
        string s;
        cin>>s;
        int i;
        for(i=0;i<35;i++)
        {
            if(s==ans[i])
            {
                cout<<"Qian"<<endl;
                break;
            }
        }
        if(i==35)
            cout<<"Kun"<<endl;
    }
    return 0;
}
