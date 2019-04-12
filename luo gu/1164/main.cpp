#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[105];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int r[10005]={0};
    r[0]=1;
    int j;
    for(i=0;i<n;i++)
    {
        for(j=m;j>=a[i];j--)
            r[j]+=r[j-a[i]];
    }
    cout<<r[m];
    return 0;
}
