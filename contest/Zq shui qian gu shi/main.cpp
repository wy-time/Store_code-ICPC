#include <iostream>
#include<queue>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        queue<int> vis;
        int n,k;
        cin>>n>>k;
        int i=1;
        for(i=0;i<n;i++)
            vis.push(i+1);
        int cnt=0;
        int nt=1;
        while(1)
        {
            int out=vis.front();
            vis.pop();
            if(nt%k==0)
            {
                cnt++;
                nt=0;
                if(cnt!=n)
                    cout<<out<<" ";
                else
                    cout<<out<<endl;
            }else
                vis.push(out);
            nt++;
            if(cnt==n)
                break;
        }
    }
    return 0;
}
