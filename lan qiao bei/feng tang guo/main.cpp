#include <iostream>
using namespace std;
typedef struct
{
    int num;
    int ff;
}st;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    const int n=t;
    st a[n];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i].num;
    }
    int sum=0;
    while(1)
    {
        bool flag=true;
        for(i=0;i<n;i++)
        {
            a[i].ff=a[i].num/2;
            a[i].num-=a[i].ff;
        }
        for(i=0;i<n-1;i++)
        {
            a[i].num+=a[i+1].ff;
        }
        a[i].num+=a[0].ff;
        if(a[0].num%2!=0)
        {
            a[0].num+=1;
            sum++;
        }
        for(i=1;i<n;i++)
        {
            if(a[i].num%2!=0)
            {
                a[i].num+=1;
                sum++;
            }
            if(a[i].num!=a[i-1].num)
            {
                flag=false;
            }
        }
        if(flag)
            break;
    }
    cout<<sum;
    return 0;
}
