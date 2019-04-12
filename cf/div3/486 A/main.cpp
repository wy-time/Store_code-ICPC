#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int i;
    int vis[105]={0};
    int ans[105]={0};
    int cnt=0;
    for(i=0;i<n;i++)
    {
        int t;
        cin>>t;
        if(vis[t]==0)
        {
            vis[t]=1;
            ans[cnt]=i+1;
            cnt++;
            if(cnt==k)
                break;
        }
    }
    if(cnt==k)
    {
        cout<<"YES"<<endl;
        for(i=0;i<cnt-1;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<ans[i];
    }else
    {
        cout<<"NO";
    }
    return 0;
}
