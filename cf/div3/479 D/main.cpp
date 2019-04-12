#include <iostream>
#include<map>
using namespace std;
typedef long long ll;
typedef map<ll,int>map1;
map1 ans;
int dfs(ll beg,int step);
ll res[105];
int n;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        if(ans.count(temp)==0)
            ans.insert(make_pair(temp,1));
        else
            ans[temp]++;
    }
    map1::iterator it;
    it=ans.begin();
    for(it=ans.begin();it!=ans.end();it++)
    {
        ans[it->first]--;
        if(dfs(it->first,1))
        {
            res[0]=it->first;
            break;
        }else
            ans[it->first]++;
    }
    for(i=0;i<n-1;i++)
        cout<<res[i]<<" ";
    cout<<res[i];
    return 0;
}
int dfs(ll beg,int step)
{
    if(step==n)
    {
        return 1;
    }else
    {
        if(ans.count(beg*2)!=0&&ans[beg*2]>0)
        {
            ans[beg*2]--;
            if(dfs(beg*2,step+1))
            {
                res[step]=beg*2;
                return 1;
            }else
                ans[beg*2]++;
        }
        if(beg%3==0&&ans.count(beg/3)!=0&&ans[beg/3]>0)
        {
            ans[beg/3]--;
            if(dfs(beg/3,step+1))
            {
                res[step]=beg/3;
                return 1;
            }else
                ans[beg/3]++;
        }
    }
    return 0;
}
