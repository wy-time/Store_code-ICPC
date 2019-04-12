#include <iostream>
using namespace std;
long long sum[200005];
int serach(long long x);
int n,m;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    int i;
    for(i=1;i<=n;i++)
    {
        long long t;
        cin>>t;
        sum[i]=sum[i-1]+t;
    }
    for(i=0;i<m;i++)
    {
        long long letter_num;
        cin>>letter_num;
        int pos=serach(letter_num);
        cout<<pos<<" "<<letter_num-sum[pos-1]<<endl;
    }
    return 0;
}
int serach(long long x)
{
    int l=1,r=n;
    int mid=0;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(sum[mid]>=x)
            r=mid-1;
        else
            l=mid+1;
    }
    return l;
}
