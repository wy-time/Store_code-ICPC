/*#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector <int> a;
bool use[100005];
void dfs(int n,int temp,int k,int step,long long sum);
int minx=0x3f3f3f3f;
int main()
{
    std::ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int r=0;
    int i;
    long long sum=0;
    for(i=0;i<n;i++)
    {
        int t;
        cin>>t;
        sum+=t;
        sum%=k;
        if(t%k==0)
        {
            r++;
        }else
            a.push_back(t);
    }
    if(sum%k==0)
    {
        cout<<n;
        return 0;
    }else
    {
        //sort(a.begin(),a.end(),greater<int>());
        int temp=sum%k;
        dfs(a.size(),temp,k,1,0);
        if(minx!=0)
            n-=minx;
        else
            n=r;
    }
    cout<<n;
    return 0;
}
void dfs(int n,int temp,int k,int step,long long sum)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(!use[i])
        {
            sum+=a[i];
            use[i]=true;
            if(sum%k==temp)
            {
                minx=min(step,minx);
            }
            else
            {
                dfs(n,temp,k,step+1,sum);
                use[i]=false;
                sum-=a[i];
            }
        }
    }
    return ;
}*/
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
    ll n;
ll getKMaxLength(ll nums[],ll sums[],ll k){
    ll Max[k];
    ll Min[k];
    for(ll i=0;i<k;i++){
        Max[i]=-1;
        Min[i]=n+1;
    }
    ll mod;
    for(ll i=0;i<n+1;i++){
        mod=sums[i]%k;
        Max[mod]=max(Max[mod],i);
        Min[mod]=min(Min[mod],i);

    }
    ll count=0;
    for(ll i=0;i<k;i++){
        if(Max[i]!=-1&&Min[i]!=n+1){
            count=max(count,Max[i]-Min[i]);
        }
    }
    return count;
}
int main(){
    ll k;
    cin>>n>>k;
    ll nums[n];
    ll sums[n+1];
    sums[0]=0;
    for(ll i=0;i<n;i++){
//      scanf("%d",&nums[i]);
        cin>>nums[i];
        sums[i+1]=sums[i]+nums[i];
    }
    cout<<getKMaxLength(nums,sums,k);

    return 0;
}
