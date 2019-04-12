#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,y;
        cin>>n>>x>>y;
        long long r=0;
        if(n<x)
        {
            cout<<0<<endl;
            continue;
        }
        else if(x>(3*y))
        {
            r+=3;
            n-=x;
            while(n>=y)
            {
                n-=y;
                r++;
            }
        }else
        {
            while(n>=x)
            {
                n-=x;
                r+=3;
            }
            while(n>=y)
            {
                n-=y;
                r++;
            }
        }
        cout<<r<<endl;
    }
    return 0;
}
