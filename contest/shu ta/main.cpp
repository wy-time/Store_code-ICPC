#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int a[100][100];
    while(t--)
    {
        int n;
        cin>>n;
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                cin>>a[i][j];
            }
        }

    }
}
