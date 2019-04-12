#include <iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("input2.txt","r",stdin);
    int n;
    char s[8005];
    cin>>n>>s;
    int a[26]= {0};
    int i,j,k;
    k=n-1;
    int center=0;
    center=n/2;
    for(i=0; i<n; i++)
    {
        a[s[i]-'a']++;
    }
    int cnt=0;
    bool flag=true;
    for(i=0; i<26; i++)
    {
        if(a[i]%2!=0)
        {
            cnt++;
            if(cnt==2)
            {
                cout<<"Impossible";
                flag=false;

            }
        }
    }
    int result=0;
    if(flag)
    {
        for(i=0; i<n-1; i++)
        {
            for(j=k; j>=i; j--)
            {
                if(i==j)
                {
                    result+=center-j;
                    break;
                }
                if(s[i]==s[j])
                {
                    result+=k-j;
                    for(int t=j;t<k;t++)
                    {
                        s[t]=s[t+1];
                    }
                    s[k]=s[i];
                    k--;
                    break;
                }
            }
        }
        cout<<result;
    }
    return 0;
}
