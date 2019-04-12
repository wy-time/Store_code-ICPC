#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,i;
        cin>>a;
        long long r,t1=1,t2=2;
        if(a-1==1)
            r=1;
        else if(a-1==2)
            r=2;
        for(i=2;i<a-1;i++)
        {
            r=t1+t2;
            t1=t2;
            t2=r;
        }
        cout<<r<<endl;
    }
}
