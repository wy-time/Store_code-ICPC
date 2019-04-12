#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    int a[10005];
    cin>>n>>m;
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
    while(m--)
        next_permutation(a,a+n);
    for(i=0;i<n-1;i++)
        cout<<a[i]<<" ";
    cout<<a[i];
    return 0;
}
