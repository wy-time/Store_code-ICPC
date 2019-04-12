#include <iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int h;
    int m;
    int s;
}tttime;
bool cmp(tttime a,tttime b)
{
    if(a.h!=b.h)
    {
        return a.h<b.h;
    }else if(a.m!=b.m)
        return a.m<b.m;
    else
        return a.s<b.s;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    tttime a[5005];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i].h>>a[i].m>>a[i].s;
    }
    sort(a,a+n,cmp);
    for(i=0;i<n;i++)
    {
        cout<<a[i].h<<" "<<a[i].m<<" "<<a[i].s<<endl;
    }
    return 0;
}
