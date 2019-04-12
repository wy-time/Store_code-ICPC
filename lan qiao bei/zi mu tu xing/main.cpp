#include<stdlib.h>
#include <iostream>
using namespace std;
int main()
{
    char a [30][30];
    int n,m;
    cin>>n>>m;
    int flag =1;
    int i;
    int j=0;
    for(i=0;i<m;i++)
    {
        a[0][i]='A'+i;
    }
    for(j=0;j<m;j++)
    {
        flag =0;
        for(i=0;i<n;i++)
        {
            if(a[i][j]=='A')
            {
                flag=1;
            }else if(a[i][j]=='Z')
            {
                flag =0;
            }
            if(flag)
            {
                a[i+1][j]=a[i][j]+1;
            }else
            {
                a[i+1][j]=a[i][j]-1;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
