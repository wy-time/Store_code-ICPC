#include <iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int id;
    int skill;
    int res;
    int fixd;
}stru;
struct rule
{
    bool operator()(const stru& a,const stru& b)
    {
        return a.skill<b.skill;
    }
};
struct rule2
{
    bool operator()(const stru& a,const stru& b)
    {
        return a.id<b.id;
    }
};
stru prog[200005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>prog[i].skill;
        prog[i].id=i+1;
        prog[i].res=0;
        prog[i].fixd=0;
    }
    for(i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        if(prog[a-1].skill>prog[b-1].skill)
        {
            prog[a-1].res--;
            prog[a-1].fixd++;
        }else if(prog[b-1].skill>prog[a-1].skill)
        {
            prog[b-1].res--;
            prog[b-1].fixd++;
        }
    }
    sort(prog,prog+n,rule());
    prog[0].res=0;
    for(i=1;i<n;i++)
    {
        if(prog[i-1].skill!=prog[i].skill)
        {
            prog[i].res+=i;
        }else
            prog[i].res+=prog[i-1].res+prog[i-1].fixd;
    }
    sort(prog,prog+n,rule2());
    for(i=0;i<n-1;i++)
    {
        cout<<prog[i].res<<" ";
    }
        cout<<prog[i].res;
    return 0;
}
