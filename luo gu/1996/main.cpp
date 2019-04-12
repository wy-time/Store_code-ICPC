#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int next[105];
    int n,m;
    cin>>n>>m;
    if(n!=0)
    {
        next[n]=1;
        int i;
        for(i=1; i<n; i++)
            next[i]=i+1;
        int cnt=0;
        for(i=1; i!=next[i]; i=next[i])
        {
            cnt++;
            if(cnt==m-1)
            {
                cnt=0;
                cout<<next[i]<<" ";
                next[i]=next[next[i]];
            }
        }
        cout<<i;
    }
    return 0;
}
