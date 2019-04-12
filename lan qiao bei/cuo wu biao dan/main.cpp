#include <iostream>
#include <algorithm>
#include <cstdio>
#include<cstring>
using namespace std;
int a[100000];
int atoix(char *temp);
int main()
{
    //std::ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    getchar();
    char temp[10]={0};
    int cnt =0;
    int i=0;
    while(n--)
    {
        while(1)
        {
            char t=getchar();
            while(t==' ')
                t=getchar();
            if(t=='\n')
            {
                break;
            }
            while(t!=' '&&t!='\n')
            {
                temp[i]=t;
                i++;
                t=getchar();
            }
            a[cnt]=atoix(temp);
            cnt++;
            int j=0;
            for(j=0;j<i;j++)
                temp[j]='\0';
            i=0;
            if(t=='\n')
            {
                break;
            }
        }
    }
    sort(a,a+cnt);
    int r1,r2;
    int cha=a[0];
    int end1=0;
    for(i=1;i<cnt;i++)
    {
        if(a[i]-i!=cha)
        {
            if(a[i]==a[i-1])
            {
                r2=a[i];
                end1++;
            }else
            {
                r1=a[i-1]+1;
                end1++;
                cha++;
            }
        }
        if(end1==2)
            break;
    }
    cout<<r1<<" "<<r2;
    return 0;
}
int atoix(char *temp)
{
    int result=0;
    int len=strlen(temp);
    int i;
    for(i=0;i<len;i++)
    {
        result=result*10+temp[i]-'0';
    }
    return result;
}
