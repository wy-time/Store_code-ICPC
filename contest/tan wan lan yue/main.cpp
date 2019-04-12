#include <iostream>
#include<string>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==0)
        {
            int a,b;
            cin>>a>>b;
            cout<<a+b<<endl;
        }else
        {
            string s;
            cin>>s;
            cout<<s.size()<<endl;
        }
    }
    return 0;
}
