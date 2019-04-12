#include <iostream>
#include<string.h>
using namespace std;
void solve(char a[],char b[],char result[]);
int main()
{
    char a[41];
    char b[41];
    char result [82];
    int i;
    cin>>a>>b;
    int len1=strlen(a);
    int len2=strlen(b);
    if(len1>len2)
    {
        solve(a,b,result);
    }
    else
    {
        solve(b,a,result);
    }
    int len3=strlen(result);
    for(i=len3-1;i>=0;i--)
    {
        cout<<result[i];
    }
    return 0;
}
void solve(char a[],char b[],char result[])
{
    int i=0,j=0,t,s=0;
    int len1=strlen(a);
    int len2=strlen(b);
    for(i=len2-1;i>=0;i--)
    {
        t=((a[len1-1-j]-'0')*(b[i]-'0'))+s;
        result[j]=(t%10)+'0';
        s=t/10;
        j++;
    }
    for(i=len1-1-j;i>=0;i--)
    {
        t=a[i]-'0'+s;
        result[j]=t%10+'0';
        s=t/10;
        j++;
    }
}
