#include <iostream>
#include<cstdio>
using namespace std;
int solve (int n,int a);
int main()
{
    int n;
    while(1)
    {
        int p[17];
        scanf("%d",&n);
        if(n==0)
            break;
        int i=0,cnt=0;
        for(i=2;i<17;i++)
        {
            p[i]=solve(n,i);
        }
        for(i=2;i<17;i++)
        {
            if(p[i]==1)
            {
                if(cnt==0)
                {
                    printf("Number %d is palindrom in basis %d",n,i);
                    cnt++;
                }else
                {
                    printf(" %d",i);
                }
            }
        }
        if(cnt==0)
        {
            printf("Number %d is not a palindrom\n",n);
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}
int solve (int n,int a)
{
    int i,j=0,p=1;
    i=n;
    int t;
    char c[32];
    while(i!=0)
    {
        t=i%a;
        if(t<10)
        {
            c[j]=t+48;
        }
        else
        {
            c[j]=t+54;
        }
        i/=a;
        j++;
    }
    for(i=0;i<j/2;i++)
    {
        if(c[i]!=c[j-1-i])
        {
            p=0;
            break;
        }
    }
    return p;
}
