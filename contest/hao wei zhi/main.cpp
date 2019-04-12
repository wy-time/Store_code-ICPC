#include <iostream>
#include<string>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    string s;
    string x;
    cin>>s>>x;
    int len=s.size();
    int len2=x.size();
    int i;
    int j=0;
    bool is=true;
    for(i=0; i<len; i++)
    {
        if(s[i]!=x[j])
        {
            int t=i;
            int k;
            int pos=x.find(s[t]);
            if(pos==string::npos)
            {
                is=false;
                break;
            }else
            {
                t-=pos;
                int temp=0;
                for(k=t;k<t+len2;k++)
                {
                    if(s[k]!=x[temp])
                    {
                        is=false;
                        break;
                    }else
                        temp++;
                }
                if(is)
                {
                    i=k-1;
                    j=0;
                    continue;
                }
                else
                    break;
            }
        }
        j++;
        j%=len2;
    }
    if(is)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
