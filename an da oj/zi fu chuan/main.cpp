#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char s[200];
        char c[200];
        cin>>s>>c;
        int len =strlen (s);
        char *p=strstr(s,c);
        if(p!=NULL)
        {
            int i;
            for(i=0;i<len;i++)
            {
                if(p==s+i)
                {
                    break;
                }
            }
            cout<<i+1<<endl;;
        }else
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}
