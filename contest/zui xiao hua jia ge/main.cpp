#include <iostream>
#include<algorithm>
using namespace std;
int people[100005];
int vis[100005];
typedef struct
{
    int can;
    int cost;
} st;
struct rule
{
    bool operator()(const st &a,const st &b)
    {
        return a.cost<b.cost;
    }
};
st info[100005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i;
    for(i=0; i<n; i++)
        cin>>people[i];
    sort(people,people+n);
    for(i=0; i<m; i++)
        cin>>info[i].can>>info[i].cost;
    sort(info,info+m,rule());
    long long res=0;
    int cnt=0;
    for(i=0; i<m&&cnt<n; i++)
    {
        int pos=upper_bound(people,people+n,info[i].can)-people;
        pos-=1;
        while(pos>=0&&vis[pos]==1)
            pos--;
        if(pos>=0)
        {
            vis[pos]=1;
            res+=info[i].cost;
            cnt++;
        }
    }
    if(cnt<n)
        cout<<-1;
    else
        cout<<res;
    return 0;
}
