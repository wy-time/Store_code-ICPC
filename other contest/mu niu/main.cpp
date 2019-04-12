#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {
        int a[3]={0};
        a[2]=1;
        int t;
        n-=1;
        while (n--)
        {
            t=a[2];
            a[2]+=a[1];
            a[1]=a[0];
            a[0]=t;
        }
        cout<<a[0]+a[1]+a[2]<<endl;;
        cin>>n;
    }
    return 0;
}
