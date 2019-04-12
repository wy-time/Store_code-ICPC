#include <iostream>
using namespace std;
int a[100005];
int b[100005];
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        long long r=0;
        register int n;
        cin>>n;
        register int i;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>b[i];
        }
        for(i=0;i<n-1;i++)
        {
            if(a[i]>b[i])
            {
                a[i+1]+=a[i]-b[i];
                r+=(a[i]-b[i]);
            }else if(a[i]<b[i])
            {
                a[i+1]-=(b[i]-a[i]);
                r+=b[i]-a[i];
            }
        }
        cout<<r<<endl;
    }
    return 0;
}
