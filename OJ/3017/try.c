#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char id[20];
    char name[30];
    int gread[3];
} student;
void input(student*p,int n);
void output(student*p,int n);
int main ()
{
    int n;
    scanf("%d",&n);
    student *p=(student*)malloc(sizeof(student)*n);
    input(p,n);
    output(p,n);
    return 0;
}
void input(student*p,int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        scanf("%s %s %d %d %d",p[i].id,p[i].name,&p[i].gread[0],&p[i].gread[1],&p[i].gread[2]);
    }
}
void output(student*p,int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%s,%s,%d,%d,%d\n",p[i].id,p[i].name,p[i].gread[0],p[i].gread[1],p[i].gread[2]);
    }
}
