#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
    int m,n,i;
    double sum;
    scanf("%d",&m);
    while(m--)
    {
        sum=0;
        scanf("%d",&n);
        int flag=1;
        for(i=0;i<n;i++)
        {
            sum+=(1.0/(i+1))*flag;
            flag=-flag;
        }
        printf("%.2f\n",sum);
    }
    return 0;
}
