#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
bool cmp(string a,string b);
int main()
{
    int n;
    cin>>n;
    string s[25];
    int i=0;
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
    sort(s,s+n,cmp);
    for(i=n-1;i>=0;i--)
    {
        cout<<s[i];
    }
    return 0;
}
bool cmp(string a,string b)
{
    if(a.size()==b.size())
        return a<b;
    else
    {
        int i;
        for(i=0;i<min(a.size(),b.size());i++)
        {
            if(a[i]<b[i]||a[i]>b[i])
            {
                return a[i]<b[i];
            }
        }
        if(a.size()<b.size())
        {
            return a[0]<b[i];
        }else
        {
            return a[i]<b[0];
        }
    }
}
