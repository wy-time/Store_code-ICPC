#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    int a[1005];
    cin>>n>>m;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    while(m--)
    {
        int opp;
        cin>>opp;
        int l=0;
        int r=0;
        switch(opp)
        {
            case 1:
                int x,y;
                cin>>r>>l>>x>>y;
                for(i=r-1;i<=l-1;i++)
                {
                    if(a[i]==x)
                    {
                        a[i]=y;
                    }
                }
                break;
            case 2:
                int k;
                cin>>r>>l>>k;
                int b[1005];
                int j=0;
                for(i=r-1;i<=l-1;i++)
                {
                    b[j]=a[i];
                    j++;
                }
                sort(b,b+j);
                cout<<b[k-1]<<endl;
        }
    }
    return 0;
}
