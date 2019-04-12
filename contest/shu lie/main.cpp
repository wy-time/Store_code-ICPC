#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    int a[101];
    int i;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
            break;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        a[i]=m;
        sort(a,a+i+1);
        for(i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<a[i]<<endl;;
    }
    return 0;
}
