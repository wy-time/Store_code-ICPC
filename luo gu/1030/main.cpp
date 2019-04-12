#include <iostream>
#include<string>
using namespace std;
void slove(string s1,string s2);
int main()
{
    std::ios::sync_with_stdio(false);
    string s1,s2;
    cin>>s1>>s2;
    cout<<s2[s2.size()-1];
    int t=s1.find(s2[s2.size()-1]);
    slove(s1.substr(0,t),s2);
    slove(s1.substr(t+1),s2);
    return 0;
}
void slove(string s1,string s2)
{
    int len1=s1.size();
    int len2=s2.size();
    if(len1>1)
    {
        int t=s2.find(s1[0]);
        t+=1;
        while(s1.find(s2[t])!=string::npos&&t!=len2)
            t++;
        t--;
        t=s1.find(s2[t]);
        cout<<s1[t];
        slove(s1.substr(0,t),s2);
        slove(s1.substr(t+1),s2);
    }else if(len1!=0)
        cout<<s1[0];
}
