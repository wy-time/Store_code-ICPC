#include <iostream>
using namespace std;
const int MAX=2000005;
int a[MAX];
int main()
{
    std::ios::sync_with_stdio(false);
    long long n,k,t;
    cin>>n>>k>>t;
    long long i;
    a[0]=1;
    for(i=1;i<k*2;i++)
    {
        a[i]=a[i-1]+i;
        a[i]%=k;
    }
    long long sum=0;
    long long length=n*t;
    for(i=0;i<length;i+=n)
    {
        int j=i%(k*2);
        sum+=a[j];
    }
    cout<<sum;
    return 0;
}
