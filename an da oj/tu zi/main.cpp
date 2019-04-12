#include <iostream>
using namespace std;
int main()
{
    long long n=1;
    while(cin>>n&&n)
    {
        long long a[2]={0};
        a[0]=1;
        int i;
        for(i=0;i<n;i++)
        {
            long long t=a[1];
            a[1]+=a[0];
            a[0]=t;
        }
        cout<<a[0]+a[1]<<endl;
    }
    return 0;
}
