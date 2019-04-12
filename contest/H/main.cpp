#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    long long a[55];
    a[0]=0;
    a[1]=1;
    a[2]=1;
    int i;
    for(i=3;i<50;i++)
    {
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
    int n;
    while(cin>>n)
    {
        cout<<a[n-1]<<endl;
    }
    return 0;
}
