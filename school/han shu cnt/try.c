/*#include<stdio.h>
void b();
int main ()
{
    int n=3;
    while (n--)
    {
        b();
    }
    return 0;
}
void b()
{
    static char a='A';
    if(a=='A')
        printf("第一次调用返回字符%c!\n",a++);
    else if(a=='B')
        printf("第二次调用返回字符%c!\n",a++);
    else
        printf("第三次调用返回字符%c!\n",a++);
}*/
#include<stdio.h>
main()
{
    int x,y,z;
    printf("Man \t Women \t Childern\n");
    for (x=1; x<16; x++)
        for (y=1; y<25; y++)
        {
            z = 30 - x - y;
            if (3 * x + 2 * y + z == 50)
                printf("%3d\t %5d\t %8d\n",x,y,z);
        }
}
