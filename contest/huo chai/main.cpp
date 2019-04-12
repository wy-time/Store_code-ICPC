#include <iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int a[10]={2,0,3,3,1,3,3,1,3,3};
    int b[10]={4,2,2,2,3,2,3,2,4,3};
    while(t--)
    {
        string s;
        cin>>s;
        int i;
        long long r1=0,r2=0;
        for(i=0;i<s.size();i++)
        {
            r1+=a[s[i]-'0'];
            r2+=b[s[i]-'0'];
        }
        cout<<r1<<" "<<r2<<endl;
    }
    return 0;
}
