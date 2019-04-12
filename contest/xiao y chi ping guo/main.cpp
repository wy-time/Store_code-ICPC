#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    long long r=1;
    int i;

    for(i=0;i<n;i++)
    {
        r*=2;
    }
    cout<<r;
    return 0;
}
