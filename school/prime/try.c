#include<stdio.h>
#include<math.h>
int main ()
{
    printf("There are follwing primes in first row :\n");
    int a[2][500];
    int i,j,k=0,t,sum,cnt;
    for(i=2000;i>=2;i--)
    {
        int c=1;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                c=0;
                break;
            }
        }
        if(c)
        {
            a[0][k]=i;
            k++;
        }
    }
    for(i=1;i<k-1;i++)
    {
        a[1][i]=a[0][i-1]-a[0][i];
    }
    sum=0,cnt=0;
    for(t=1;t<k;t++)
    {
        for(i=1;i<k;i++)
        {
            sum=0;
            for(j=t;j<=i;j++)
            {
                sum+=a[1][j];
            }
            if(sum==1898)
            {
                cnt++;
                printf("(%d).%3d,......,%d\n",cnt,a[0][j-1],a[0][t-1]);
            }
        }
    }
    return 0;
}
