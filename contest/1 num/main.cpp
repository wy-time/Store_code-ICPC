#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int cnt =0;
    int i=0;
    int c;
    for(i=1;i<=n;i++)
    {
        int t=i;
        while(t!=0)
        {
            c=t%10;
            if(c==1)
            {
                cnt++;
            }
            t/=10;
        }
    }
    cout<<cnt;
    return 0;
}
