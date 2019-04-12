#include<string>
#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool is[20];
int main()
{
    string s[20],r[20];
    memset(is,true,sizeof(is));
    int t;
    cin>>t;
    int i,j,k;
    getchar();
    for(i=0;i<t;i++)
    {
        getline(cin,s[i]);
    }
    k=0;
    for(i=0;i<t;i++)
    {
        if(is[i])
        {
            r[k]+=(i+'0');
            is[i]=false;
            for(j=i+1;j<t;j++)
            {
                if(is[j])
                {
                    if(s[i]==s[j])
                    {
                        r[k]+=(j+'0');
                        is[j]=false;
                    }
                }
            }
            k++;
        }
    }
    int max1=0;
    for(i=0;i<k;i++)
    {
        if(r[i].size()>max1)
        {
            max1=r[i].size();
            t=i;
        }
    }
    for(i=0;i<r[t].size()-1;i++)
    {
        cout<<(r[t][i]-'0')+1<<" ";
    }
    cout<<(r[t][i]-'0')+1<<endl;;
    return 0;
}
