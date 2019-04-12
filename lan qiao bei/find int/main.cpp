#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    const int l=n;
    int a[l];
    int i;
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int aim;
    cin>>aim;
    int result=0;
    int flag=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==aim)
        {
            result=i;
            flag=1;
            break;
        }
    }
    if(flag)
    {
        cout<<result+1;
    }else
    {
        cout<<-1;
    }
    return 0;
}
