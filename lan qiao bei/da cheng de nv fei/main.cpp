#include <iostream>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;
void slove(int beg,int sum);
int temp;
long long maxx;
bool vis[10005];
struct node
{
    int b;
    int cast;
};
vector<node>G[10010];
node st;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    for(i=0; i<n-1; i++)
    {
        int v;
        int a,b;
        cin>>a>>b>>v;
        st.b=b;
        st.cast=v;
        G[a].push_back(st);
        st.b=a;
        G[b].push_back(st);
    }
    slove(1,0);
    vis[i]=false;
    slove(temp,0);
    long long result=maxx*11+(maxx*(maxx-1)/2);
    cout<<result;
    return 0;
}
void slove(int beg,int sum)
{
    vis[beg]=true;
    int i;
    if(sum>maxx)
    {
        maxx=sum;
        temp=beg;
    }
    for(i=0; i<G[beg].size(); i++)
    {
        node s1=G[beg][i];
        if(!vis[s1.b])
        {
            sum+=s1.cast;
            slove(s1.b,sum);
            vis[s1.b]=false;
            sum-=s1.cast;
        }
    }
}
