#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    int res=0;
    cin>>n;
    int t=-100;
    int maxx=0;
    while(n--)
    {
        int temp;
        cin>>temp;
        temp>t?res++:res=1;
        t=temp;
        maxx=max(res,maxx);
    }
    cout<<maxx;
    return 0;
}
