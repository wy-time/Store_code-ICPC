#include <iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef struct
{
    int bugs;
    int brain;
} st;
st room[300];
vector <int> link[200];
void dfs (ll get_brain,int startship,int now,int last);
ll getmax;
int visit[200];
int viscnt;
int m,n;
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        if(n==1&&m==-1)
            break;
        fill(visit,visit+200,0);
        int i;
        viscnt=0;
        getmax=0;
        for(i=0;i<200;i++)
            link[i].clear();
        for(i=1; i<=n; i++)
        {
            cin>>room[i].bugs>>room[i].brain;
        }
        for(i=0; i<n-1; i++)
        {
            int t1,t2;
            cin>>t1>>t2;
            link[t1].push_back(t2);
            link[t2].push_back(t1);
        }
        dfs(0,m,1,0);
        cout<<getmax<<endl;
    }
    return 0;
}
void dfs (ll get_brain,int startship,int now,int last)
{
    if(startship<(room[now].bugs/20+room[now].bugs%20>0?1:0)||startship==0)
        return ;
    if(viscnt==n)
        return ;
    if(visit[now]==0)
    {
        get_brain+=room[now].brain;
        startship-=(room[now].bugs/20+room[now].bugs%20>0?1:0);
        visit[now]=1;
        viscnt++;
    }
    int len=link[now].size();
    int flag=0;
    if(visit[now]!=2&&visit[now]==1)
    {
        for(int i=0;i<len;i++)
        {
            if(visit[link[now][i]]!=1)
            {
                flag=1;
                break;
            }
        }
    }
    if(!flag)
        visit[now]=2;
    for(int i=0;i<len;i++)
    {
        if(visit[link[now][i]]!=2&&(link[now][i]!=last||visit[now]==2))
        {
            if(link[now][i]==last&&room[i].bugs==0)
                startship--;
            dfs(get_brain,startship,link[now][i],now);
        }
    }
    visit[now]=2;
    getmax=max(getmax,get_brain);
}
