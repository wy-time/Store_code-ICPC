#include <iostream>
#include<string>
using namespace std;
int ans[1000005];
bool feng (int n);
int main()
{
    std::ios::sync_with_stdio(false);
    ans[1]=1;
    int i;
    for(i=2;i<=1000000;i++)
    {
        if(feng(i))
        {
            ans[i]=ans[i-1]+1;
        }else
        {
            ans[i]=ans[i-1];
        }
    }
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
        {
            break;
        }
        int result=(m-n+1)-(ans[m]-ans[n-1]);
        if(n==0||m==0)
            result--;
        cout<<result<<endl;
    }
    return 0;
}
bool feng (int n)
{
    int t;
    string s="";
    while(n!=0)
    {
        t=n%10;
        if(t==4)
        {
            return false;
        }
        s+=(t+'0');
        n/=10;
    }
    int flag=s.find("83");
    if(flag!=-1)
        return false;
    else
        return true;
}
