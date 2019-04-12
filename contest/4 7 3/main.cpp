#include <iostream>
#include<string>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int vis=0;
    int temp;
    while(k--)
    {
        temp=s.find("47");
        if(temp==-1)
            break;
        else
        {
            if((1+temp)%2==0)
            {
                if(s[temp-1]!='4')
                {
                    s[temp]='7';
                }else
                {
                    vis=1;
                    break;
                }
            }else
            {
                if(s[temp+2]!='7')
                {
                    s[temp+1]='4';
                }else
                {
                    vis=2;
                    break;
                }
            }
        }
    }
    k++;
    if(vis)
    {
        if(vis==1)
        {
            int t=k%2;
            if(t)
            {
                s[temp]='7';
            }
        }else
        {
            int t=k%2;
            if(t)
            {
                s[temp+1]='4';
            }
        }
    }
    cout<<s;
    return 0;
}
