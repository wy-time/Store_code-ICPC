#include <iostream>
using namespace std;
const int MAXN=1000005;
bool notprime[MAXN];
int ans[MAXN];
int main()
{
    std::ios::sync_with_stdio(false);
    int i;
    notprime[1]=true;
    for(i=2;i<MAXN;i++)
    {
        if(!notprime[i])
        {
            ans[i]=ans[i-1]+1;
            for(int j=2*i;j<=MAXN;j+=i)
                notprime[j]=true;
        }else
            ans[i]=ans[i-1];
    }
    int t,m;
    cin>>t>>m;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        if(l<=0||r>m)
            cout<<"Crossing the line"<<endl;
        else
        {
            int res=ans[r]-ans[l];
            if(!notprime[l])
                res++;
            cout<<res<<endl;
        }
    }
    return 0;
}
