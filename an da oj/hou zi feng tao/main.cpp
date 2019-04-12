#include <iostream>
using namespace std;
int main()
{
    long long i=0,t,a,n;
    while(cin>>n&&n)
    {
        if(n==1)
        {
            cout<<1<<" "<<1<<endl;
        }else
        {
            int cnt=1;
            for(i=1;cnt!=n; i++)
            {
                cnt=1;
                t=i;
                if(t%5!=1)
                    continue;
                else
                {
                    do
                    {
                        a=cnt;
                        t-=1;
                        t-=t/5;
                        if(t%5==1)
                            cnt++;
                        if(a==cnt||cnt==n)
                            break;
                    }
                    while(1);
                    if(cnt==n)
                    {
                        t-=1;
                        t-=t/5;
                        cout<<i<<" "<<t+n<<endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
