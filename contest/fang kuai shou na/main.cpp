#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    cin>>t;
    long long ans[100]={0};
    ans[1]=1;
    ans[2]=2;
    while(t--)
    {
        int n;
        cin>>n;
        if(ans[n]==0)
        {
            int i;
            for(i=3;i<=n;i++)
            {
                ans[i]=ans[i-1]+ans[i-2];
            }
        }
        cout<<ans[n]<<endl;
    }
    return 0;
}
