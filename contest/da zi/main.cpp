#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char s[100005];
typedef struct
{
    char w;
    char a;
    char b;
}q;
bool cmp(q a, q b);
q info [100005];
int main()
{
    int m;
    cin>>s;
    cin>>m;
    int i=0;
    for(i=0;i<26;i++)
    {
        info[i].a=i+'a';
        info[i].b=i+'a';
    }
    while(m--)
    {
        char c,d;
        cin>>c>>d;
        int t1,t2;
        int safe=0;
        for(i=0;i<26;i++)
        {
            if(c==info[i].a)
            {
                t1=i;
                safe++;
            }
            if(d==info[i].a)
            {
                t2=i;
                safe++;
            }
            if(safe==2)
                break;
        }
        info[t1].a=d;
        info[t2].a=c;
    }
    sort(info,info+26,cmp);
    int len=strlen(s);
    for(i=0;i<len;i++)
    {
        int temp=s[i]-'a';
        s[i]=info[temp].b;
    }
    cout<<s;
    return 0;
}
bool cmp(q a, q b)
{
    return a.a<b.a;
}
