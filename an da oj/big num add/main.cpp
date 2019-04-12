#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
std::string jian(std::string s1,std::string s2);
int main()
{
    int fushu=0;
    string s1,s2,s3;
    cin>>s1>>s2;
    if((s1[0]=='-'&&s2[0]=='-')||(s1[0]!='-'&&s2[0]!='-'))
    {
        if(s1[0]=='-'&&s2[0]=='-')
        {
            fushu=1;
            s1.erase(0,1);
            s2.erase(0,1);
        }
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        int i,j;
        for(i=0; i<min(s1.size(),s2.size()); i++)
        {
            if(s1.size()>s2.size())
            {
                s1[i]=s2[i]+s1[i]-'0';
                for(j=i;j<s1.size();j++)
                {
                    while(s1[j]>=10+'0')
                    {
                        if(j+1==s1.size())
                        {
                            char c=(s1[j]-'0')/10+'0';
                            if(c!='0')
                                s1+=c;
                        }else
                        {
                            s1[j+1]+=((s1[j]-'0')/10);
                        }
                            s1[j]=(s1[j]-'0')%10+'0';
                    }
                }
            }
            else
            {
                s2[i]=s1[i]+s2[i]-'0';
                for(j=i;j<s2.size();j++)
                {
                    while(s2[j]>=10+'0')
                    {
                        if(j+1==s2.size())
                        {
                            char c=(s2[j]-'0')/10+'0';
                            if(c!='0')
                                s2+=c;
                        }else
                        {
                            s2[j+1]+=((s2[j]-'0')/10);
                        }
                            s2[j]=(s2[j]-'0')%10+'0';
                    }
                }
            }
        }
        if(fushu)
        {
            cout<<"-";
        }
        if(s1.size()>s2.size())
        {
            reverse(s1.begin(),s1.end());
            cout<<s1;
        }
        else
        {
            reverse(s2.begin(),s2.end());
            cout<<s2;
        }
    }
    else
    {
        if(s1[0]=='-')
        {
            s1.erase(0,1);
            int mode=0;
            if(s1>s2)
                mode=1;
            else if(s1<s2)
                mode=2;
            reverse(s1.begin(),s1.end());
            reverse(s2.begin(),s2.end());
            if(s1.size()>s2.size())
            {
                fushu=1;
                s3=jian(s1,s2);
            }
            else if(s1.size()<s2.size())
            {
                fushu=0;
                s3=jian(s2,s1);
            }
            else
            {
                if(mode==1)
                {
                    fushu=1;
                    s3=jian(s1,s2);
                }
                else if(mode==2)
                {
                    fushu =0;
                    s3=jian(s2,s1);
                }
                else
                {
                    cout<<0;
                }
            }
        }
        else
        {
            s2.erase(0,1);
            int mode=0;
            if(s1>s2)
                mode=1;
            else if(s1<s2)
                mode=2;
            reverse(s1.begin(),s1.end());
            reverse(s2.begin(),s2.end());
            if(s1.size()>s2.size())
            {
                fushu=0;
                s3=jian(s1,s2);
            }
            else if(s1.size()<s2.size())
            {
                fushu=1;
                s3=jian(s2,s1);
            }
            else
            {
                if(mode==1)
                {
                    fushu=0;
                    s3=jian(s1,s2);
                }
                else if(mode==2)
                {
                    fushu =1;
                    s3=jian(s2,s1);
                }
                else
                {
                    cout<<0;
                }
            }
        }
        reverse(s3.begin(),s3.end());
        if(fushu)
        {
            cout<<"-";
        }
        cout<<s3;
    }
    return 0;
}
std::string jian(std::string s1,std::string s2)
{
    int i,j;
    for(i=0;i<s2.size();i++)
    {
        if(s1[i]>=s2[i])
        {
            s1[i]=s1[i]-s2[i]+'0';
        }
        else
        {
            s1[i+1]=s1[i+1]-1;
            s1[i]=s1[i]-s2[i]+'0'+10;
            for(j=i+1;j<s1.size();j++)
            {
                while(s1[j]<'0')
                {
                    s1[j]+=10;
                    s1[j+1]-=1;
                }
            }
            while(*s1.rbegin()=='0')
            {
                s1.erase(--s1.end());
            }
        }
    }
    return s1;
}
