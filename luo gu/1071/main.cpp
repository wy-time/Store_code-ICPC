#include <iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
int main()
{
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    typedef map<char,char>mp;
    mp map1;
    int safe=1;
    int i;
    int len=s1.size();
    for(i=0;i<len;i++)
    {
        pair<mp::iterator,bool> pa=map1.insert(make_pair(s1[i],s2[i]));
        if(!pa.second)
        {
            if(pa.first->second!=s2[i])
            {
                safe=0;
                break;
            }
        }
    }
    if(map1.size()<26)
        safe=0;
    else
    {
        set <char> st;
        mp::iterator it;
        for(it=map1.begin();it!=map1.end();it++)
        {
            st.insert(it->second);
        }
        if(st.size()!=26)
            safe=0;
    }
    if(safe)
    {
        len=s3.size();
        for(i=0;i<len;i++)
        {
            cout<<map1[s3[i]];
        }
    }else
    {
        cout<<"Failed";
    }
    return 0;
}
