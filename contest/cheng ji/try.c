#include<stdio.h>
#include<stdlib.h>
int  main ()
{
    int n,m,i,j;
    while (scanf("%d %d",&n,&m)!=EOF)
    {
        double sums[5]={0};
        double sum=0;
        int a[50][5];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(j=0;j<m;j++)
        {
            for(i=0;i<n;i++)
            {
                sums[j]+=a[i][j];
            }
            sums[j]/=n;
        }
        for(i=0;i<n;i++)
        {
            sum =0;
            for(j=0;j<m;j++)
            {
                sum+=a[i][j];
            }
            sum/=m;
            printf("%.2f%c",sum," \n"[i==n-1]);
        }
        int cnt=0;
        for(i=0;i<n;i++)
        {
            int p=1;
            for(j=0;j<m;j++)
            {
                if(a[i][j]<sums[j])
                {
                    p=0;
                    break;
                }
            }
            if(p)
            {
                cnt++;
            }
        }
        for(i=0;i<m;i++)
        {
            printf("%.2f%c",sums[i]," \n"[i==m-1]);
        }
        printf("%d\n",cnt);
        printf("\n");
    }
    return 0;
}
