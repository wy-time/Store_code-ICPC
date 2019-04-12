#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int i,j;
        int r;
        cin>>r;
        int a[r][r];
        for(i=0;i<r;i++)
        {
            for(j=0;j<=i;j++)
            {
                cin>>a[i][j];
            }
        }
        int sum =a[0][0];
        j=0;
        for(i=1;i<r;i++)
        {
            if(a[i][j]>=a[i][j+1])
            {
                sum+=a[i][j];

            }
            else
            {
                sum+=a[i][j+1];
                j=j+1;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
