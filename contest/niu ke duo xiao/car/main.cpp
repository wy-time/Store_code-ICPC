#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int hang[100005]= {0};
    int lie[100005]= {0};
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        hang[a]=1;
        lie[b]=1;
    }
    int i;
    int ans=2*n-(n%2);
    for(i=1;i<=n;i++)
    {
        if(hang[i])
            ans--;
        if(lie[i])
            ans--;
    }
    if(n%2==1&&hang[(n+1)>>1]&&lie[(n+1)>>1])
        ans++;
    cout<<ans<<endl;
    return 0;
}
