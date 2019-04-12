#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    long long min1=999999999999999;
    for(i=0;i<n;i++)
    {
        long long temp;
        cin>>temp;
        min1=min(temp*temp,min1);
    }
    cout<<min1+1<<endl;
    return 0;
}
