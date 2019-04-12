#include<Stdio.h>
void move(int n, int x, int y);
void dong (int n, int A, int C, int B);
int main ()
{
    int n;
    printf("Input the number of disks:");
    scanf("%d",&n);
    printf("Steps of moving %d disks from A to B by means of C:\n",n);
    dong(n,0,2,1);
    return 0;
}
void move(int n, int x, int y)
{
    printf("Move %d: from %c to %c\n",n,x+65,y+65);
}
void dong (int n, int A, int B, int C)
{
    if(n==1)
        move(n,A,C);
    else
    {
        dong(n-1,A,C,B);
        move(n,A,C);
        dong(n-1,B,A,C);
    }
}
