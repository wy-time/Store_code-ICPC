#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int w,n;
    cin>>w>>n;
    int a[30005];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int j=n-1;
    int sum=0;
    for(i=0;i<=j;i++,j--)
    {
        int cnt=0;
        while(a[i]+a[j]>w&&i<j)
        {
            cnt++;
            j--;
        }
        sum+=cnt+1;
    }
    cout<<sum<<endl;
    return 0;
}
