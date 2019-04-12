#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
struct rule
{
    bool operator()(const string&a,const string &b)
    {
        if(a.size()!=b.size())
            return a.size()<b.size();
        else
        {
            if(a.find(b)!=string::npos)
            {
                return false;
            }else
            {
                return true;
            }
        }
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s[105];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
    sort(s,s+n,rule());
    for(i=0;i<n-1;i++)
    {
        string temp1=s[i+1];
        if(temp1.find(s[i])==string::npos)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}
