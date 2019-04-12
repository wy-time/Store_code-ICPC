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
        string s;
        cin>>s;
        int r=0;
        r=(s[2]-'A'+1)+(s[1]-'A'+1)*19+(s[0]-'A'+1)*19*19;
        int aim=7238;
        cout<<aim-r<<endl;
    }
    return 0;
}
