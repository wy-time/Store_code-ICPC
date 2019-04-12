#include <iostream>
#include<algorithm>
using namespace std;
int ans[100005];
int res[100005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    for(i=0; i<n; i++)
    {
        cin>>ans[i];
    }
    int cnt=0;
    if(n==1||n==0)
    {
        cout<<0;
        return 0;
    }
    bool o_shu=false;
    if(n%2==0)
        o_shu=true;
    for(int k=0; k<n/2; k++)
    {
        int one=ans[k]-k;
        if(one<=0)
            continue;
        res[one]++;
    }
    int k;
    if(!o_shu)
        k=n/2+1;
    else
        k=n/2;
    for(; k<n; k++)
    {
        int one=ans[k]-(n-1-k);
        if(one<=0)
            continue;
        res[one]++;
    }
    if(!o_shu)
    {
        res[ans[n/2]-n/2]++;
    }
    int temp=-1;
    int one=0;
    for(i=1;i<=100002;i++)
    {
        if(temp<res[i])
        {
            temp=res[i];
            one=i;
        }
    }
    for(i=0;i<n/2;i++)
    {
        if(ans[i]!=one+i)
        {
            cnt++;
            ans[i]=one+i;
        }
        if(ans[n-1-i]!=ans[i])
        {
            cnt++;
        }
    }
    if(!o_shu)
    {
        if(ans[n/2]-n/2!=one)
            cnt++;
    }
    cout<<cnt;
    return 0;
}
