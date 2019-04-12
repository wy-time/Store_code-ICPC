#include<string.h>
#include <iostream>
using namespace std;
int main()
{
    int n=1000;
    int m=9999;
    int i,j=0;
    char a[5]={"0"};
    char b[5]={"0"};
    for(i=n;i<=m;i++)
    {
        j=0;
        int t=i;
        while(t!=0)
        {
            a[j]=t%10+'0';
            b[3-j]=t%10+'0';
            j++;
            t/=10;
        }
        if(strcmp(a,b)==0)
        {
            cout<<i<<endl;
        }
    }
    return 0;
}
