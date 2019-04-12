#include <iostream>
#include<string>
#include<ctype.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    string s;
    string s1;
    while(t--)
    {
        int k;
        cin>>s>>k;
        int safe =0;
        int len=s.size();
        int i=0;
        while(k--)
        {
            safe =0;
            for(i=0; i<len-1; i++)
            {
                if(s[i]<s[i+1])
                {
                    safe=1;
                    s[i]='a';
                    break;
                }
            }
            int j=0;
            if(!safe)
            {
                s[len-1]='\0';
                len--;
            }
            else
            {

                for(i=0; i<len; i++)
                {
                    if(isalpha(s[i]))
                    {
                        continue;
                    }
                    else
                    {
                        s1.append(s,i,1);
                        j++;
                    }
                }
                len--;
                s1[j]='\0';
                s=s1;
                s1="";
            }

        }
        for(i=0; i<len; i++)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
