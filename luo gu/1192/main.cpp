#include <iostream>
using namespace std;
int a[100005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int i;
    a[0]=1;
    for(i=1;i<=k;i++)
    {
        int j;
        for(j=0;j<i;j++)
        {
            a[i]+=a[j];
        }
        a[i]%=100003;
    }
    for(i=k+1;i<=n;i++)
    {
        int j;
        for(j=i-k;j<i;j++)
        {
            a[i]+=a[j];
        }
        a[i]%=100003;
    }
    cout<<a[n];
    return 0;
}
