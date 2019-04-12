#include <iostream>
#include<algorithm>
using namespace std;
char s[100005];
typedef struct
{
    int pos;
    int length;
}st;
st ans[100005];
int ans2[100005];
bool cmp(st a,st b);
;int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    cin>>s;
    int i;
    int cnt=0;
    bool f=false;
    int temp=0;
    int k=0;
    if(s[0]=='b')
    {
        for(i=1;i<n;i++)
        {
            if(s[i]=='a')
            {
                k=i;
                break;
            }
        }
        if(k==0)
        {
            cout<<0;
            return 0;
        }
    }
    for(i=k;i<n;i++)
    {
        if(s[i]!=s[i+1])
        {
            if(!f)
            {
                temp=i+1;
                f=true;
            }
            else
            {
                ans2[temp]=i+1-temp;
                ans[cnt].pos=temp;
                ans[cnt].length=i+1-temp;
                cnt++;
                temp=i+1;
            }
        }
    }
    if(temp<n)
    {
        ans2[temp]=n-temp;
        ans[cnt].pos=temp;
        ans[cnt].length=n-temp;
        cnt++;
    }
    sort(ans,ans+cnt,cmp);
    int cnttt=cnt;
    int fix=0;
    for(i=0;i<cnt&&cnttt>m;i++)
    {
        if(ans2[ans[i].pos]!=0)
        {
            if(ans[i].pos==temp-1&&cnttt-1>m)
            {
                fix=ans[i].length;
                continue;
            }
            n-=ans[i].length;
            cnttt--;
            if(ans2[ans[i].pos+ans[i].length]!=0)
            {
                cnttt--;
                ans2[ans[i].pos+ans[i].length]=0;
            }
        }
    }
    if(cnttt>m)
    {
        n-=fix;
    }
    cout<<n-k;
    return 0;
}
bool cmp(st a,st b)
{
    if(a.length!=b.length)
        return a.length<b.length;
    else
        return a.pos<b.pos;
}
