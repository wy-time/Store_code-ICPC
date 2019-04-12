#include <iostream>
#include <algorithm>
using namespace std;
typedef struct st
{
    int l;
    int w;
    bool operator>(const st &a)const
    {
        return l>a.l;
    }
    bool operator<(const st &a)const
    {
        return l<a.l;
    }
}st;
st info[5005];
int low[5005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
        cin>>info[i].l>>info[i].w;
    sort(info+1,info+n+1,greater<st>());
    low[1]=info[1].w;
    int res=1;
    for(i=2;i<=n;i++)
    {
        if(info[i].w>low[res])
            low[++res]=info[i].w;
        else
        {
            int pos=lower_bound(low+1,low+1+res,info[i].w)-low;
            low[pos]=info[i].w;
        }
    }
    cout<<res;
    return 0;
}
