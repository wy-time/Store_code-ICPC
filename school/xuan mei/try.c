#include<stdio.h>
int main ()
{
    int i;
    int a[21]={1,5,3,2,3,1,3,4,2,4,7,5,5,3,1,6,5,3,7,6,4};
    printf("  Player_NO  Score  Rank\n");
    for(i=1;i<=21;i+=3)
    {
        printf("   %3d    %4d   %4d\n",a[i-1],a[i],a[i+1]);
    }
    return 0;
}
