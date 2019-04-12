#include <iostream>
using namespace std;
int a[10005];
int main()
{
    int n;
    int safe=0;
    while(cin>>n)
    {
        if(!a[n])
        {
            if(safe)
            {
                cout<<" ";
            }
            cout<<n;
            safe=1;
            a[n]=1;
        }
    }
    return 0;
}
