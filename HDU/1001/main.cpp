#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    long long n;
    while(cin>>n)
    {
        long long result=0;
        result=(n+n*n)/2;
        cout<<result<<endl<<endl;
    }
    return 0;
}
