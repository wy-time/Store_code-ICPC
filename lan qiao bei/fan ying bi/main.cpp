#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    char s1[1005];
    char s2[1005];
    cin>>s1>>s2;
    int len =strlen(s1);
    int cnt=0;
    bool flag=true;
    int i;
    int result=0;
    for(i=0;i<len;i++)
    {
        if(s1[i]!=s2[i])
        {
            if(flag)
            {
                cnt=i;
                flag=false;
            }
            else
            {
                cnt=i-cnt;
                result+=cnt;
                cnt=0;
                flag=true;
            }
        }
    }
    cout<<result<<endl;
    return 0;
}
