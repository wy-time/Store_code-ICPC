#include <iostream>
#include<algorithm>
using namespace std;
int a[2505];
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int i;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n,greater<int>());
        for(i=1;i<n;i++)
        {
            if(k<=(i*i+i)/2)
            {
                break;
            }
        }
        cout<<a[i]<<endl;
    }
    return 0;
}
