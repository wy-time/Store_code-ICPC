#include<stdio.h>
int dfs (int r);
int main ()
{
    int n;
    scanf("%d", &n);
    int r = 0;
    while(n--)
    {
        r = r * 10 + 2;
    }
    int a=dfs(r);
    printf("%d\n",a);
    return 0;
}
int dfs (int r)
{
    int sum=0;
    if(r==2){
        return 2;
    }else{
        sum =r+dfs(r/10);
    }
    return sum;
}
