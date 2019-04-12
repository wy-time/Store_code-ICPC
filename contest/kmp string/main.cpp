#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[1000005];
int next[1000005];
char temp[500005];
void getnext(int len);
void findx();
int main()
{
    //std::ios::sync_with_stdio(false)
    gets(s);
    int len=strlen(s);
    getnext(len);
    if(next[len-1]==-1)
        cout<<"Just a legend"<<endl;
    else
    {
        int t=next[len-1];
        for(i=0;i<t;i++)
        {
            temp[i]=s[i];
        }
        for(i=0;i<t;i++)
        {
            temp[t-i]='\0';
        }
    }
    return 0;
}
void getnext(int len)
{
    next[0]=-1;
    int i;
    for(i=1;i<len;i++)
    {
        int k=next(i-1);
        while(k>=0&&s[i]!=s[k+1])
        {
            k=next[k];
        }
        if(s[i]==s[k+1])
        {
            next[i]=k+1;
        }else
            next[i]=-1;
    }
}
void findx()
{

}
