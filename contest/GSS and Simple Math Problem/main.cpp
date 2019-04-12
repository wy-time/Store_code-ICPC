#include <iostream>
using namespace std;
#include<cstring>
char a[1000005],b[1000005];
int ans[1000005];
void tanping(int a[],int wei);
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    cin>>a>>b;
    a[0]=t;
    b[0]=t2;
    int weia=1,weib=1,weians;
    weia=tanping(a,weia);
    weib=tanping(b,weib);
    for(i=0;i<weia;i++)
    {
        for(int j=0;j<weib;j++)
        {
            ans[i+j]+=a[i]*b[j];
        }
        weians=i+j
    }
    weians=tanping(ans,weians);
    memcpy(a,ans,sizeof(ans));
    n-=2;
    while(n--)
    {
        cin>>t;
        b[0]=t;
    }
    return 0;
}
int tanping(int a[],int wei)
{
    for(i=0;i<wei||a[i]!=0;i++)
    {
        if(a[i]>10)
        {
            a[i+1]+=ans[i]/10;
            a[i]%=10;
        }
        weia=i+1;
    }
    return wei;
}
