#include <iostream>
#include<string.h>
using namespace std;
#define s 32
int main()
{
    int i,j=0;
    int t;
    int a[5]={0};
    for(i=0;i<s;i++)
    {
        memset(a,0,sizeof(a));
        j=0;
        t=i;
        while(t!=0)
        {
            a[j]=t%2;
            t/=2;
            j++;
        }
        for(j=4;j>=0;j--)
        {
            cout<<a[j];
        }
        cout<<endl;
    }
}
