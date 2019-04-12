#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int i;
    int a[100005];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int cnt=0;
    int sum=0;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum==m&&i!=n-1)
        {
            cnt++;
            sum=0;
        }else if(sum>m)
        {
            cnt++;
            sum=0;
            i--;
        }
    }
    cout<<cnt+1<<endl;
    return 0;
}
