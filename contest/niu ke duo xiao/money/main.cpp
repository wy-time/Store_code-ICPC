#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long a[100005]={0};
        int i;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        long long sum=0;
        long long times=0;
        long long temp=0;
        bool flag=false;
        for(i=0;i<n;i++)
        {
            if(!flag)
            {
                if(a[i]<a[i+1])
                {
                    temp=a[i];
                    flag=true;
                    times++;
                }
            }else
            {
                if(a[i]>a[i+1])
                {
                    sum+=a[i]-temp;
                    times++;
                    flag=false;
                }
            }
        }
        cout<<sum<<" "<<times<<endl;
    }
    return 0;
}
