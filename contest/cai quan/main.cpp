#include <iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    typedef map<string,string>map1;
    map1 ma;
    string s1,s2,s3;
    string t1[6];
    int i;
    int cnt=0;
    for(i=0;i<3;i++)
    {
        cin>>s1>>s2;
        ma.insert(make_pair(s2,s1));
        t1[cnt++]=s1;
        t1[cnt++]=s2;
    }
    int n;
    cin>>n;
    s3=t1[1];s2=t1[3];s1=t1[5];
    while(n--)
    {
        string s;
        cin>>s;
        if(s==s1||s==s2||s==s3)
        {
            cout<<ma[s]<<endl;
        }else
        {
            cout<<"Fake"<<endl;
            continue;
        }
    }
    return 0;
}
