/*4296*/
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct
{
    int w;
    int s;
}st;
st info[1000005];
bool cmp(st a,st b);
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        int i;
        for(i=0;i<n;i++)
        {
            cin>>info[i].w>>info[i].s;
        }
        sort(info,info+n,cmp);
        long long temp=0;
        long long sum=0;
        for(i=0;i<n;i++)
        {
            sum=max(temp-info[i].s,sum);
            temp+=info[i].w;
        }
        cout<<sum<<endl;
    }
    return 0;
}
bool cmp(st a,st b)
{
    return a.s+a.w<b.s+b.w;
}
