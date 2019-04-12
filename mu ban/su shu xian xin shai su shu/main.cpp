#include <iostream>
#include<cstring>
using namespace std;
bool prime[10000005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    int i;
    for(i=2;i<=n;i++)
    {
        if(prime[i])
        {
            for(int j=i*2;j<=n;j+=i)
                prime[j]=false;
        }
    }
    for(i=0;i<m;i++)
    {
        int a;
        cin>>a;
        if(prime[a])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
