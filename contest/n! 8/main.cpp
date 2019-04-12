#include <iostream>
#include<cmath>
const double pi=acos(-1.0);
const double e=2.718281828459;
using namespace std;
long long a[10000005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    double sum;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(a[n]==0)
        {
            sum=0.0;
            sum=log10(sqrt(2*pi*n))/log10(1.0*8)+n*log10(n/e)/log10(1.0*8);
            a[n]=(long long)sum+1;
        }
        cout<<a[n]<<endl;
    }
    return 0;
}
