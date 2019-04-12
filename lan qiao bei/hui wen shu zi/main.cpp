#include<string.h>
#include <iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    int n=10000;
    int m=999999;
    int i;
    char b[7]={"0"};
    char c[7]={"0"};
    int j,k;
    int sum;
    int cnt=0;
    for(i=n;i<=m;i++)
    {
        sum=0;
        j=0;
        int t=i;
        while(t!=0)
        {
            b[j]=t%10+'0';
            sum+=t%10;
            t/=10;
            j++;
        }
        if(sum!=a)
        {
            continue;
        }

        for(k=0;k<j;k++)
        {
            c[j-1-k]=b[k];
        }
        if(strcmp(b,c)==0)
        {
            cout<<i<<endl;
            cnt++;
        }
    }
    if(cnt==0)
    {
        cout<<-1<<endl;
    }
    return 0;
}
