#include <iostream>
using namespace std;
void msort(int a[],int l,int r);
void mcmp(int a[],int l,int mid,int r);
int cnt;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    int a[40005];
    for(i=0;i<n;i++)
        cin>>a[i];
    msort(a,0,n-1);
    cout<<cnt;
    return 0;
}
void msort(int a[],int l,int r)
{
    int mid=(l+r)/2;
    if(l<r)
    {
        msort(a,l,mid);
        msort(a,mid+1,r);
        mcmp(a,l,mid,r);
    }
}
void mcmp(int a[],int l,int mid,int r)
{
    int b[40005]={0};
    int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r)
    {
        if(a[i]>a[j])
        {
            b[k++]=a[j++];
            cnt+=mid+1-i;
        }else
        {
            b[k++]=a[i++];
        }
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=r)
        b[k++]=a[j++];
    for(i=0;i<k;i++)
    {
        a[l+i]=b[i];
    }
}
