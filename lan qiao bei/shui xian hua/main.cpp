#include<math.h>
#include <iostream>
using namespace std;
int main()
{
    int m=100;
    int n=999;
    int i;
    double sum;
    double a[3];
    for(i=m;i<=999;i++)
    {
        sum =0;
        int j=0;
        int t=i;
        while(t!=0)
        {
            a[j]=t%10;
            t/=10;
            j++;
        }
        for(j=0;j<3;j++)
        {
            sum+=pow(a[j],3.0);
        }
        if(sum==i)
        {
            cout<<i<<endl;
        }
    }
    return 0;
}
