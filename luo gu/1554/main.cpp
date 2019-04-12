#include <iostream>
using namespace std;
int ans[10];
void slove(long long n);
int main()
{
    std::ios::sync_with_stdio(false);
    long long m,n;
    cin>>m>>n;
    long long i;
    for(i=m;i<=n;i++)
    {
        slove(i);
    }
    for(i=0;i<9;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<ans[i];
    return 0;
}
void slove(long long n)
{
    while(n)
    {
        ans[n%10]++;
        n/=10;
    }
}
