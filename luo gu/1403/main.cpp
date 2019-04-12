#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    long long sum=0;
    int i;
    for(i=1;i<=n;i++)
        sum+=n/i;
    cout<<sum;
    return 0;
}
