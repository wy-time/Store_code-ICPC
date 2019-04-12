#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[105];
    int i;
    int sum=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int avg=sum/n;
    int cnt=0;
    for(i=0;i<n;i++)
    {
        if(a[i]<avg)
        {
            a[i+1]-=avg-a[i];
            cnt++;
        }else if(a[i]>avg)
        {
            int t=a[i]-avg;
            a[i]-=t;
            a[i+1]+=t;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
