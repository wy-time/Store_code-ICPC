#include <iostream>
using namespace std;
int main()
{
    int n,m,i,sum,cnt;
    while(cin>>n>>m)
    {
        i=1;
        cnt=0;
        sum=0;
        while(n/m!=0)
        {
            cnt=0;
            if(sum!=0)
                cout<<" ";
            sum=0;
            n-=m;
            for(; cnt<m; i++)
            {
                sum+=i*2;
                cnt++;
            }
            cout<<sum/m;
        }
        if(n==0)
            cout<<endl;
        else
        {
            cout<<" ";
            cnt=0;
            sum=0;
            for(; cnt<n; i++)
            {
                sum+=i*2;
                cnt++;
            }
            cout<<sum/n<<endl;
        }
    }
    return 0;
}
