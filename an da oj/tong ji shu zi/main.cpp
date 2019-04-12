#include <iostream>
#include<algorithm>
using namespace std;
int a[200000];
int main()
{
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+i);
    int t=0;
    for(i=0;i<n;i++)
    {
        if(a[i]!=a[i+1])
        {
            cout<<a[i]<<" "<<i-t+1<<endl;
            t=i+1;
        }
    }
    return 0;
}
