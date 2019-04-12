#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    char x[105];
    char y[105];
    cin>>x>>y;
    int i;
    for(i=0;i<n;i++)
    {
        if(y[i]!=min(x[i],y[i]))
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<y;
    return 0;
}
