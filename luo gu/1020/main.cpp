#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int low[100005];
int main()
{
    std::ios::sync_with_stdio(false);
    int a[100005]={0};
    int n=1;
    while(cin>>a[n++]);
    n-=2;
    low[1]=a[n];
    int res1=1;
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]>=low[res1])
            low[++res1]=a[i];
        else
        {
            int pos=upper_bound(low+1,low+1+res1,a[i])-low;
            low[pos]=a[i];
        }
    }
    cout<<res1<<endl;
    memset(low,0,sizeof(low));
    low[1]=a[1];
    int res2=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>low[res2])
            low[++res2]=a[i];
        else
        {
            int pos=lower_bound(low+1,low+1+res2,a[i])-low;
            low[pos]=a[i];
        }
    }
    cout<<res2<<endl;
    return 0;
}
