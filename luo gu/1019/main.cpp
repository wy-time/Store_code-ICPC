#include <iostream>
#include<string>
using namespace std;
void slove(int n,std::string s);
string s[25];
int use[25];
std::string isnext(std::string s1,std::string s2);
int max1;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    fill(use,use+25,2);
    cin>>n;
    int i;
    for(i=0; i<n; i++)
    {
        cin>>s[i];
    }
    char beg;
    cin>>beg;
    for(i=0;i<n;i++)
    {
        if(s[i][0]==beg)
        {
            use[i]--;
            slove(n,s[i]);
            use[i]++;
        }
    }
    cout<<max1<<endl;
    return 0;
}
void slove(int n,std::string s1)
{
    int t=s1.size();
    int i;
    max1=max(max1,t);
    for(i=0; i<n; i++)
    {
        if(use[i])
        {
            string temp=isnext(s1,s[i]);
            if(s1!=temp)
            {
                use[i]--;
                slove(n,temp);
                use[i]++;
            }
        }
    }
}
std::string isnext(std::string s1,std::string s2)
{
    int len1=s1.size();
    int len2=s2.size();
    int i;
    int t;
    i=0;
    for(int j=len1-1;j>0;j--)
    {
        if(s1[j]==s2[0])
        {
            t=j;
            while(s1[t]==s2[i])
            {
                t++;
                i++;
            }
            if(t==len1&&i!=len2)
                break;
            else
            {
                i=0;
            }
        }
    }
    if(i!=0)
    {
        s2.erase(0,i);
        s1+=s2;
    }
    return s1;
}
