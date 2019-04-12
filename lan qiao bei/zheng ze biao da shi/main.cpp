#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    char s[1005];
    cin>>s;
    int i;
    int len=strlen(s);
    int maxx=0;
    int cnt=0;
    bool flag=false;
    for(i=0;i<len;i++)
    {
        if(s[i]=='(')
        {
            if(flag)
            {
                if(cnt>maxx)
                    maxx=cnt;
                cnt=0;
            }else
                flag=true;
        }else if(s[i]=='x')
        {
            cnt++;
        }
    }
    cout<<max(maxx,cnt);
    return 0;
}
