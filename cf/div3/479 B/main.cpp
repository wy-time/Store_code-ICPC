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
    int ans[105]={0};
    int i;
    for(i=0;i<n-1;i++)
    {
        string temp="";
        temp+=s[i];
        temp+=s[i+1];
        int cnt=0;
        int pos=s.find(temp,i);
        while(pos!=string::npos)
        {
            cnt++;
            pos++;
            pos=s.find(temp,pos);
        }
        ans[i]=cnt;
    }
    int res=-1;
    int r=0;
    for(i=0;i<n;i++)
    {
        if(ans[i]>res)
        {
            res=ans[i];
            r=i;
        }
    }
    cout<<s[r]<<s[r+1];
    return 0;
}
