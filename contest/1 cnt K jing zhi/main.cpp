#include <iostream>
using namespace std;
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        int sum=0;
        int temp=k;
        sum+=n/k;
        int t=n;
        n/=k;
        while(n>0)
        {
            if(n%k>1)
            {
                n/=k;
                sum+=(n+1)*temp;
                temp*=k;
            }
            else if(n%k==1)
            {
                sum+=n/k*temp;
                sum+=(t%temp)+1;
                temp*=k;
                n/=k;
            }else
            {
                sum+=n/k*temp;
                temp*=k;
                n/=k;
            }
        }
        if(t%k>=1)
            sum++;
        cout<<sum<<endl;
    }
    return 0;
}
