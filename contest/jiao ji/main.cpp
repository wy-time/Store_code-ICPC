#include <iostream>
#include<algorithm>
using namespace std;
int a[1000005];
int b[1000005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m)
    {
        bool first=true;
        int i;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<m;i++)
            cin>>b[i];
        int j=0;i=0;
        while(i<n&&j<m)
        {
            if(a[i]<b[j])
                i++;
            else if(a[i]>b[j])
                j++;
            else
            {
                if(first)
                {
                    first=false;
                    cout<<a[i];
                }else
                    cout<<" "<<a[i];
                i++;
                j++;
            }
        }
        if(first)
            cout<<"empty";
        cout<<endl;
    }
    return 0;
}
