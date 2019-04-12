#include <iostream>
using namespace std;
struct A
{
    int h;
    int cnt;
    A()
    {
        h=0;
        cnt=0;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    A a[100005];
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i].h;
    }
    int j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j].h>a[j+1].h)
            {
                a[j].cnt++;
                a[j+1].cnt++;
                int temp=a[j+1].h;
                a[j+1].h=a[j].h;
                a[j].h=temp;
                temp=a[j+1].cnt;
                a[j+1].cnt=a[j].cnt;
                a[j].cnt=temp;
            }
        }
    }
    long long sum=0;
    for(i=0;i<n;i++)
    {
        int n=a[i].cnt;
        sum+=(n+n*(n-1)/2);
    }
    cout<<sum;
    return 0;
}
