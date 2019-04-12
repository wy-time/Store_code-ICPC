#include<string.h>
#include <iostream>
#include<stdlib.h>
using namespace std;
char a[1000];
char b[1000];
void fanzhuan(char*a,char*b);
void add (int n,char *a,char *b);
int main()
{

    int n;
    int cnt=0;
    cin>>n;
    cin>>a;
    while(cnt<=30)
    {
        fanzhuan(a,b);
        if(strcmp(a,b)==0)
            break;
        add(n,a,b);
        cnt++;
    }
    if(cnt>30)
    {
        cout<<"Impossible!";
    }else
        cout<<"STEP="<<cnt;
    return 0;
}
void fanzhuan(char*a,char*b)
{
    int len=strlen(a);
    int i;
    for(i=0;i<len;i++)
    {
        b[len-1-i]=a[i];
    }
}
void add (int n,char *a,char *b)
{
    int len=strlen(a);
    int i;
    int t;
    for(i=0;i<len;i++)
    {
        if(b[i]>63)
        {
            b[i]-=55;
        }else
        {
            b[i]-='0';
        }
        if(a[i]>63)
        {
            a[i]-=55;
        }else
        {
            a[i]-='0';
        }
    }
    for(i=0;i<len;i++)
    {
        a[i]=a[i]+b[i];
    }
    for(i=len-1;i>0;i--)
    {
        t=a[i]/n;
        a[i]%=n;
        a[i-1]+=t;
        a[i]+='0';
    }
    t=a[i]/n;
    a[i]%=n;
    a[i]+='0';
    if(t!=0)
    {
        memset(b,'\0',sizeof(b));
        b[0]=t+'0';
        strcat(b,a);
        strcpy(a,b);
    }
    strcpy(b,a);
}
