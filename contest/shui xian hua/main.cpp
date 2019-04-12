#include <iostream>
#include<math.h>
using namespace std;
int is(int m);
int main()
{
    int m;
    cin>>m;
    int i;
    int flag=1;
    for(i=m;flag==1;i++)
    {
        flag=is(i);
    }
    cout<<i-1<<endl;
    return 0;
}
int is(int m)
{
    double a[4];
    double t=m;
    int i=0;
    double sum=0;
    int flag;
    while(m!=0)
    {
        a[i]=m%10;
        m/=10;
        i++;
    }
    double j=i;
    for(i-=1;i>=0;i--)
    {
        sum+=(pow(a[i],j));
    }
    if(sum==t)
    {
        flag =0;
    }
    else
    {
        flag =1;
    }
    return flag;
}
