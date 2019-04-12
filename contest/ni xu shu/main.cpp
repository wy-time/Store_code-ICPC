#include <iostream>
using namespace std;
int a[100005];
int temp [100005];
long long sum;
void slove (int s,int e);
void mysort(int s1,int e1,int s2,int e2);
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    slove(0,n-1);
    cout<<sum;
    return 0;
}
void slove (int s,int e)
{
    if(s<e)
    {
        int mid=(s+e)/2;
        slove(s,mid);
        slove(mid+1,e);
        mysort(s,mid,mid+1,e);
    }
}
void mysort(int s1,int e1,int s2,int e2)
{
    int cnt=0;
    int p1=s1;
    int p2=s2;
    while(p1<=e1&&p2<=e2)
    {
        if(a[p1]<=a[p2])
        {
            temp[cnt]=a[p1];
            cnt++;
            p1++;
        }
        else
        {
            temp[cnt]=a[p2];
            sum+=(e1-p1+1);
            cnt++;
            p2++;
        }
    }
    while(p1<=e1)
    {
        temp[cnt]=a[p1];
        cnt++;
        p1++;
    }
    while(p2<=e2)
    {
        temp[cnt]=a[p2];
        cnt++;
        p2++;
    }
    int i;
    for(i=s1; i<=e2; i++)
    {
        a[i]=temp[i-s1];
    }
}
