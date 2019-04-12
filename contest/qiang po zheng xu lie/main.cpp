#include <iostream>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cnt=0;
    while(t--)
    {
        int n;
        cin>>n;
        int i;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        while(a[0]!=a[n-1])
        {
            for(i=0;i<n-1;i++)
            {
                a[i]++;
            }
            sort(a,a+n);
            cnt++;
        }
        cout<<cnt<<" "<<a[0]<<endl;;
    }
    return 0;
}
