#include <iostream>
using namespace std;
int main()
{
    int n,t,sum;
    cin>>n;
    while(n!=0)
    {
        n-=1;
        int a[3]={0};
        a[2]=1;
        while(n--)
        {
            t=a[2];
            a[2]+=a[1];
            a[1]=a[0];
            a[0]=t;
        }
        sum=a[0]+a[1]+a[2];
        cout<<sum<<endl;
        cin>>n;
    }
    return 0;
}
