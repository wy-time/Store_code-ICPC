#include<stdio.h>
int main ()
{
    printf("****TIME****\n");
    printf("1.Morinig\n2.afternoon\n3.night\n");
    int i;
    printf("Enter your choice:");
    scanf("\n%d",&i);
    switch(i)
    {
        case 1:
            printf("Good Morinig\n");
            break;
        case 2:

            printf("Good afternoon\n");
            break;
        case 3:
            printf("Good night\n");
            break;
        default:
            printf("Selection wrong\n");
    }
    return 0;
}
