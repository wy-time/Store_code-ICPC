#include <iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string s,s1;
        cin>>s;
        if(s.find('.')==-1)
        {
            s1=s;
        }else
        {
            int k;
            k=s.find('.');
            if(s[k-1]=='0'+9)
            {
                s1=s.substr(0,k);
            }else if(s[k+1]>=5+'0')
            {
                s[k-1]+=1;
                s1=s.substr(0,k);
            }else
            {
                s1=s.substr(0,k);
            }
        }
        while(*s1.begin()=='0'&&s1.size()!=1)
        {
            s1.erase(s1.begin());
        }
        cout<<s1<<endl;
    }
    return 0;
}
