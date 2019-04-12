#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int m;
    cin>>m;
    register int n;
    register int i;
    register int t;
    for(i=0;i<m;i++)
    {
        n=(0.5-i)+sqrt((i-0.5)*(i-0.5)+2*m);
        t=n*i+n*(n-1)/2;
        if(t==m)
        {
            cout<<i<<" "<<i+n-1<<endl;
        }
    }
    return 0;
}
