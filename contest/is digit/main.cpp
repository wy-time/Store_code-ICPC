#include <iostream>
#include<ctype.h>
#include<string.h>
using namespace std;
int main()
{
    int n,i;
    char c[100];
    cin>>n;
    while(n--)
    {
        int cnt =0;
        cin>>c;
        int len =strlen(c);
        for(i=0;i<len;i++)
        {
            if(isdigit(c[i]))
            {
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
