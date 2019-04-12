#include<algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    int *a;
    int i;
    cin>>n;
    int sum=0;
    a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    cout<<a[n-1]<<endl<<a[0]<<endl<<sum;
    free(a);
    return 0;
}
