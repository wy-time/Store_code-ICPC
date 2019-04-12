#include <iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int s;
    int e;
}st;
bool cmp1(st a,st b);
st a[1000005];
int main()
{

    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i].s>>a[i].e;
    }
    sort(a,a+n,cmp1);
    int max1=a[0].e;
    int cnt=1;
    for(i=1;i<n;i++)
    {
        if(a[i].s>=max1)
        {
            max1=a[i].e;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
bool cmp1(st a,st b)
{
    return a.e<b.e;
}
