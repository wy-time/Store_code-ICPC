#include <iostream>
#include<cmath>
using namespace std;
typedef struct
{
    long long x;
    long long y;
}st;
st point[5005];
double cla(st x,st y);
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int r;
    int n;
    cin>>r>>n;
    register int i=0;
    register int j;
    int t=n;
    while(t--)
    {
        cin>>point[i].x>>point[i].y;
        ++i;
    }
    int ans=1;
    register int r2=2*r;
    for(i=0;i<n;++i)
    {
        register short flag=0;
        for(j=i+1;j<n;++j)
        {
            double temp=cla(point[i],point[j]);
            if(temp<=r2)
            {
                flag=1;
            }
        }
        if(!flag&&i+1!=n)
            ++ans;
    }
    cout<<ans;
    return 0;
}
inline double cla(st a,st b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
