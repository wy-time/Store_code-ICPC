#include <iostream>
using namespace std;
int a[100005];
int main()
{
    std::ios::sync_with_stdio(false);
    long long n,d;
    cin>>n>>d;
    long long i,j;
    long long t=0;
    long long cnt=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        for(j=t;j<=i-2;j++)
        {
            if(a[i]-a[j]>d)
            {
                t=j+1;
            }else
            {
                long long nn=i-j-1;
                cnt+=(nn*nn+nn)/2;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
