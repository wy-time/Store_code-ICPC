#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    char a[4];
    while(cin>>a)
    {
        sort(a,a+3);
        cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
    }
    return 0;
}
