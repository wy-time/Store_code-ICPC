#include <iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
bool slove(int sum,int times,int aim);
int cnt;
int n,k;
int a[20];
bool b[20];
int ans[20];
typedef map <set<int>,int> map1;
map1 ma;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>k;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        memset(b,false,sizeof(b));
        slove(0,0,i);
    }
    if(cnt==0)
        cout<<"No"<<endl;
    else
    {
        set<int> st;
        map1::iterator it1;
        for(it1=ma.begin(),i=0;i<cnt;i++,it1++)
        {
            st=it1->first;
            set <int>::iterator it;
            for(it=st.begin();it!=st.end();it++)
            {
                cout<<*it<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
bool slove(int sum,int times,int aim)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(b[i]==false)
        {
            sum+=a[i];
            b[i]=true;
            ans[times]=a[i];
        }else
            continue;
        if (times!=aim-1)
        {
            if(sum>k)
            {
                ans[times]=0;
                b[i]=false;
                sum-=a[i];
                continue;
            }else
            {
                if(!slove(sum,times+1,aim))
                {
                    ans[times]=0;
                    b[i]=false;
                    sum-=a[i];
                }
            }
        }else
        {
            if(sum==k)
            {
                int j=0;
                set <int> st;
                for(j=0;j<aim;j++)
                {
                    st.insert(ans[j]);
                }
                pair<map1::iterator ,bool> res;
                res=ma.insert(make_pair(st,cnt));
                if(res.second)
                    cnt++;

            }
            sum-=a[i];
            b[i]=false;
            ans[times]=0;
            continue;
        }
    }
    return false;
}
