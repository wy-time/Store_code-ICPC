#include<math.h>
#include <iostream>
#define minn 0.9999999999
using namespace std;
int main()
{
    long long n,m;
    while(cin>>n>>m)
    {
        long long x,y;
        if(n<m)
        {
            cout<<n;
        }
        else
        {
            x=((sqrt(8.0*(n*1.0-m*1.0)+1.0)-1.0))/2.0+minn;
            x+=m;
        }
            cout<<x;
    }
    return 0;
}
