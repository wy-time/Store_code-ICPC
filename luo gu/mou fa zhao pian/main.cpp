#include <iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int bian;
    int id;
    int quan;
}s;
bool cmp(s a,s b);
int main()
{
    int n,k;
    s a[20005];
    int e[20005];
    cin>>n>>k;
    int i;
    for(i=0;i<10;i++)
    {
        cin>>e[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>a[i].quan;
        a[i].bian=i+1;
    }
    sort(a,a+n,cmp);
    for(i=0;i<n;i++)
    {
        a[i].id=(i%10)+1;
        a[i].quan+=e[a[i].id-1];
    }
    sort(a,a+n,cmp);
    for(i=0;i<k-1;i++)
    {
        cout<<a[i].bian<<" ";
    }
    cout<<a[i].bian<<endl;
    return 0;
}
bool cmp(s a,s b)
{
    if(a.quan!=b.quan)
        return a.quan>b.quan;
    else
        return a.bian<b.bian;
}
