#include <iostream>
#include<cctype>
#include<cstdio>
using namespace std;
int main()
{
    int p1,p2,p3;
    cin>>p1>>p2>>p3;
    string s;
    cin>>s;
    int temp=-1;
    while(s.find('-',temp+1)!=-1)
    {
        temp=s.find('-',temp+1);
        if((isdigit(s[temp-1])&&isdigit(s[temp+1]))||(islower(s[temp-1])&&islower(s[temp+1])))
        {
            if(s[temp+1]>s[temp-1]+1)
            {
                if(p1!=3)
                {
                    if(p3==1)
                    {
                        if(p1==1||(isdigit(s[temp-1])))
                        {
                            string t="";
                            int i;
                            for(i=(int)s[temp-1]+1;i<(int)s[temp+1];i++)
                            {
                                int q=p2;
                                while(q--)
                                {
                                    t.push_back(i);
                                }
                            }
                            s.erase(temp,1);
                            s.insert(temp,t);
                        }else
                        {
                            string t="";
                            int i;
                            for(i=(int)s[temp-1]+1;i<(int)s[temp+1];i++)
                            {
                                int q=p2;
                                while(q--)
                                {
                                    t.push_back(i-('a'-'A'));
                                }
                            }
                            s.erase(temp,1);
                            s.insert(temp,t);
                        }
                    }else
                    {
                        if(p1==1||isdigit(s[temp-1]))
                        {
                            string t="";
                            int i;
                            for(i=(int)s[temp+1]-1;i>(int)s[temp-1];i--)
                            {
                                int q=p2;
                                while(q--)
                                {
                                    t.push_back(i);
                                }
                            }
                            s.erase(temp,1);
                            s.insert(temp,t);
                        }else
                        {
                            string t="";
                            int i;
                            for(i=(int)s[temp+1]-1;i>(int)s[temp-1];i--)
                            {
                                int q=p2;
                                while(q--)
                                {
                                    t.push_back(i-('a'-'A'));
                                }
                            }
                            s.erase(temp,1);
                            s.insert(temp,t);
                        }
                    }
                }else
                {
                    string t="";
                    int i;
                    for(i=(int)s[temp+1]-1;i>(int)s[temp-1];i--)
                    {
                        int q=p2;
                        while(q--)
                        {
                            t.push_back('*');
                        }
                    }
                    s.erase(temp,1);
                    s.insert(temp,t);
                }
            }else if(s[temp+1]==s[temp-1]+1)
            {
                s.erase(temp,1);
            }
        }
    }
    cout<<s;
    return 0;
}
