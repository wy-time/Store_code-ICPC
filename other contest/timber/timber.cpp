#include <iostream>
#define minn 0.999999999999999
using namespace std;
int a[300000];
int b[300000];
int c[300000];
int d[300000];
//int e[300000];
int main()
{
    long long n,s,l,sum;
    cin>>n>>s>>l;
    long long i,j=0;
    long long t;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        cin>>b[i];
    }
    for(i=0; i<n; i++)
    {
        t=0;
        if(a[i]>=l)
        {
            c[t]+=a[i];
            d[t]+=b[i];

        }else
        {
            t=(((double)l-a[i])/b[i]+minn);

            c[t]+=a[i]+t*b[i];
            d[t]+=b[i];
        }
    }
    sum =0;
    long long q=0;
    for(i=0;;i++)
    {
        sum+=c[i]+q;
        q+=d[i];
        if(sum>=s)
        {
            break;
        }
    }
    cout<<i;
    return 0;
}
