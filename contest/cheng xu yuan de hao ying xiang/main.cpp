#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int low[105];
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        memset(low+1,-1,sizeof(low));
        int ans[105];
        int i;
        int res=0;
        for(i=1;i<=n;i++)
        {
            cin>>ans[i];
        }
        low[1]=ans[1];
        res=1;
        for(i=2;i<=n;i++)
        {
            if(ans[i]>=low[res])
            {
                low[++res]=ans[i];
            }else
            {
                int pos=upper_bound(low+1,low+res+1,ans[i])-low;
                low[pos]=ans[i];
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
