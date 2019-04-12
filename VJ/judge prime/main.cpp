#include <iostream>
#include <math.h>
using namespace std;
int isprime(int a);
int main()
{
    int x,y,i,j;
    while(cin>>x>>y)
    {
        j=1;
        if(x==0&&y==0)
            break;
        for(i=x;i<=y;i++)
        {
            if(!isprime(i))
            {
                j=0;
                break;
            }
        }
        if(j)
            cout<<"OK"<<endl;
        else
            cout<<"Sorry"<<endl;
    }
    return 0;
}
int isprime(int a)
{
    a=a*a+a+41;
    int i=0;
    int j=1;
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
        {
            j=0;
            break;
        }
    }
    return j;
}
