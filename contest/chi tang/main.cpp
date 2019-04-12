#include <iostream>
using namespace std;
int main()
{
    int n;
    int a[10005];
    cin>>n;
    int i=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int m;
    cin>>m;
    long long max1=0;
    while(m--)
    {
        int b,e;
        cin>>b>>e;
        int sum=0;
        for(i=b-1;i<e;i++)
        {
            sum+=a[i];
        }
        if(sum>0)
        {
            max1+=sum;
        }
    }
    cout<<max1<<endl;
    return 0;
}
