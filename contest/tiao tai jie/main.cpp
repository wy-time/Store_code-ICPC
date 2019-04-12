#include<iostream>
using namespace std;
int main ()
{
    long long ans[35];
    int t;
    cin>>t;
    ans[1]=1;
    ans[2]=2;
    int i;
    for(i=3;i<=30;i++)
    {
        ans[i]=2*ans[i-1];
    }
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ans[n]<<endl;;
    }
    return 0;
}
