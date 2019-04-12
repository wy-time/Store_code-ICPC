#include<stdio.h>
int main ()
{
    long a[2][100];
    int t;
    int safe=1;
    int i;
    long  id=0,f=0;
    printf("Input student¡¯s ID and score:");
    scanf("%ld %ld",&id,&f);
    for(i=0;id>=0&&f>=0;i++)
    {
        a[0][i]=id;
        a[1][i]=f;
        printf("Input student¡¯s ID and score:");
        scanf("%ld %ld",&id,&f);
    }
    t=i;
    printf("Total students are %d\n",i);
    printf("Input the searching ID:");
    scanf("%ld",&id);
    for(i=0;i<t;i++)
    {
        if(a[0][i]==id)
        {
            printf("score =  %ld\n",a[1][i]);
            safe =0;
        }
    }
    if(safe)
    {
        printf("Not found!\n");
    }
    return 0;
}
