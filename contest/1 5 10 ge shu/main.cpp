#include <iostream>
using namespace std;
int main()
{
    int k;
    cin>>k;
    int a[60]={0};
    int t;
    int i;
    for(i=0;i<k;i++)
    {
        cin>>t;
        a[t]++;
    }
    cout<<a[1]<<" "<<a[5]<<" "<<a[10]<<endl;
    return 0;
}
