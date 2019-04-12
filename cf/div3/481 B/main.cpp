#include <iostream>
#include<string>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<n-2;i++)
    {
        int t=s.find("xxx",i);
        if(t!=string::npos)
        {
            cnt++;
            i=t;
        }else
            break;
    }
    cout<<cnt;
    return 0;
}
