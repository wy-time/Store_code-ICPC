#include <iostream>
#include<map>
#include<vector>
using namespace std;
typedef map<int,int>map1;
map1 vis1;
typedef struct
{
    int v;
    int p;
}pos;
typedef map<int,pos>map2;
map2 ma;
vector<pos> vis;
int main()
{
    std::ios::sync_with_stdio(false);
    int k;
    cin>>k;
    int i,j=0;
    int flag=0;
    while(k--)
    {
        j++;
        int n;
        cin>>n;
        int sum=0;
        vis1.clear();
        vis.clear();
        for(i=0;i<n;i++)
        {
            int t;
            cin>>t;
            if(flag==0)
            {
                sum+=t;
                if(vis1.count(t)==0)
                {
                    vis1.insert(make_pair(t,1));
                    pos temp={t,i+1};
                    vis.push_back(temp);
                }
            }
        }
        if(flag==0)
        {
            for(int k=0;k<vis.size();k++)
            {
                int tem=sum-vis[k].v;
                if(ma.count(tem)==0)
                {
                    pos temp={j,vis[k].p};
                    ma.insert(make_pair(tem,temp));
                }else
                {
                    cout<<"YES"<<endl;
                    cout<<ma[tem].v<<" "<<ma[tem].p<<endl;
                    cout<<j<<" "<<vis[k].p<<endl;
                    flag=1;
                    break;
                }
            }
        }
    }
    if(flag==0)
        cout<<"NO"<<endl;
    return 0;
}
