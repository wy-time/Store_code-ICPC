#include <iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
bool cmp( pair<int,int>a,pair<int,int>b);
int main()
{
    int n;
    cin>>n;
    pair<int,int>p[1005];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>p[i].first;
        p[i].second=i;
    }
    stable_sort(p,p+n,cmp);
    int sum[1005];
    sum[0]=0;
    double result=sum[0];
    for(i=1;i<n;i++)
    {
        sum[i]=p[i-1].first+sum[i-1];
        result+=sum[i];
    }
    for(i=0;i<n-1;i++)
    {
        cout<<p[i].second+1<<" ";
    }
    cout<<p[i].second+1<<endl;
    printf("%.2f",result/n);
}
bool cmp( pair<int,int> a,pair<int,int> b)
{
    return a.first<b.first;
}
