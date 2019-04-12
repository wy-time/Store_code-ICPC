#include <iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int dps;
    int hp;
}st;
bool cmp(st a,st b);
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    st info[20];
    while(cin>>n)
    {
        int i;
        for(i=0;i<n;i++)
        {
            cin>>info[i].dps>>info[i].hp;
        }
        sort(info,info+n,cmp);
        int ans=0,temp=0;
        for(i=0;i<n;i++)
        {
            ans+=info[i].dps*(info[i].hp+temp);
            temp+=info[i].hp;
        }
        cout<<ans<<endl;
    }
    return 0;
}
bool cmp(st a,st b)
{
    return a.dps*b.hp>a.hp*b.dps;
}
