#include <iostream>
int minm(int a,int b);
using namespace std;
int main()
{
    int n,a,b,c;
    int sum=0;
    cin>>n>>a>>b>>c;
    int minx=minm(a,minm(b,c));
    int minx1=minm(a,b);
    if(n!=1)
    {
        sum+=minx1;
        n-=2;
        while(n--)
        {
            sum+=minx;
        }
    }
    cout<<sum;
    return 0;
}
int minm(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}
