#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int m,n;
    cin>>m>>n;
    int cnt=0;
    while(m%2!=0&&n%2!=0)
    {
        cnt++;
        m=(m-1)/2;
        n=(n-1)/2;
    }
    long long result=0;
    while(cnt)
    {
        cnt--;
        result+=(int)pow(4.0,(double)cnt);
    }
    cout<<result;
    return 0;
}
