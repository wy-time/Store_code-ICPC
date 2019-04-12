#include <iostream>
#include <set>
#include<algorithm>
using namespace std;
typedef struct
{
    int l;
    int r;
}st;
st qu[100005];
int ans[100005];
struct rule
{
	bool operator () (const st & a,const st & b)
	{
		if(a.l == b.l)
        	return a.r > b.r;
    	return a.l < b.l;
	}
};
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        fill(ans+1,ans+n+1,1);
        int i;
        for(i=0;i<m;i++)
        {
            cin>>qu[i].l>>qu[i].r;
        }
        sort(qu,qu+m,rule());
        set <int> use;
        for(i=1;i<=n;i++)
        {
            use.insert(i);
        }
        st pre={0,-1};
        for(i=0;i<m;i++)
        {
            if(qu[i].l>=pre.l&&qu[i].r<=pre.r)
                continue;
            for(int j=pre.l;j<=min(pre.r,qu[i].l-1);++j)
                use.insert(ans[j]);
            for(int j=max(pre.r+1,qu[i].l);j<=qu[i].r;++j)
            {
                ans[j]=*use.begin();
                use.erase(ans[j]);
            }
            pre=qu[i];
        }
        for(i=1;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<ans[i]<<endl;
    }
}
