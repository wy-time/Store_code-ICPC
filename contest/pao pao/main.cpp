#include <iostream>
#include<string>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    string s;
    while(cin>>s)
    {
        int i;
        int tttt=3;
        while (tttt--)
        {
            int len=s.size();
            for(i=0;i<len;i++)
            {
                int cnt=0;
                if(s[i]=='o')
                {
                    if(i-1>=0&&s[i-1]=='o')
                    {
                        s[i-1]='O';
                        s.erase(i,1);
                        len--;
                        i--;
                    }else if(s[i+1]=='o')
                    {
                        s[i]='O';
                        s.erase(i+1,1);
                        len--;
                        cnt++;
                    }
                }
                if(s[i]=='O')
                {
                    if(i-1>=0&&s[i-1]=='O')
                    {
                        s.erase(i-1,2);
                        len-=2;
                        i--;
                    }else if(s[i+1]=='O')
                    {
                        s.erase(i,2);
                        len-=2;
                        cnt++;
                    }
                }
                if(cnt!=0)
                    i--;
            }
        }
        cout<<s<<endl;
        s="";
    }
    return 0;
}/*
#include<stdio.h>
#include<string.h>

char s[105];

int main()
{
    while(~scanf("%s",s))
    {
        int i,j,len=strlen(s);
        for(i=1;i<len;i++)
        {
            if(s[i]=='o')
            {
                j=i;
                while(j--)
                {
                    if(s[j]=='o')
                    {
                        s[j]='w';
                        s[i]='O';
                        j=i;
                        while(j--)
                        {
                            if(s[j]=='O')
                            {
                                s[j]='w';
                                s[i]='w';
                            }
                            if(s[j]=='o')break;
                        }
                        break;
                    }
                    if(s[j]=='O')break;
                }
            }

            if(s[i]=='O')
            {
                j=i;
                while(j--)
                {
                    if(s[j]=='O')
                    {
                        s[j]='w';
                        s[i]='w';
                    }
                    if(s[j]=='o')break;
                }
            }
        }
        for(i=0;i<len;i++)
            if(s[i]=='w')continue;
            else printf("%c",s[i]);
        printf("\n");
    }
	return 0;
}*/
