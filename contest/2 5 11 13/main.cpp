#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    long long n;
    while(cin>>n)
    {
        long long t=0;
        t += n / 2;
        t += n / 5;
        t += n / 11;
        t += n / 13;
        t -= n / 2 / 5;
        t -= n / 2 / 11;
        t -= n / 2 / 13;
        t -= n / 5 / 11;
        t -= n / 5 / 13;
        t -= n / 11 / 13;
        t += n / 2 / 5 / 11;
        t += n / 2 / 5 / 13;
        t += n / 2 / 11 / 13;
        t += n / 5 / 11 / 13;
        t -= n / 2 / 5 / 11 / 13;
        cout<<n-t<<endl;
    }
    return 0;

}
