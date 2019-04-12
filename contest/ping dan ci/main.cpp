#include <iostream>
#include<string>
#include<cstring>
using namespace std;
int have[26];
int main()
{
    std::ios::sync_with_stdio(false);
    string s;
    while(cin>>s)
    {
        int i;
        memset(have,0,sizeof(have));
        for(i=0;i<s.size();i++)
        {
            have[s[i]-'a']++;
        }
        int n;
        cin>>n;
        int maxx=0;
        while(n--)
        {
            int havetemp[26];
            bool can=true;
            memcpy(havetemp,have,sizeof(have));
            string s2;
            cin>>s2;
            for(i=0;i<s2.size();i++)
            {
                if(havetemp[s2[i]-'a']-1<0)
                {
                    can=false;
                    break;
                }
                else
                {
                    havetemp[s2[i]-'a']--;
                }
            }
            if(can)
            {
                int len=s2.size();
                maxx=max(maxx,len);
            }
        }
        cout<<maxx<<endl;
    }
    return 0;
}
