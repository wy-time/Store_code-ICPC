#include <iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int i;
    int len=s.size();
    if(s.find('5')==string::npos)
    {
        if(s.find('0')!=string::npos)
        {
            if(s.find('0',s.find('0')+1)==string::npos)
            {
                cout<<-1<<endl;
                return 0;
            }
        }else
        {
            cout<<-1<<endl;
            return 0;
        }
    }else
    {
        if(s.find('0')==string::npos&&s.find('2')==string::npos&&s.find('7')==string::npos)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    int res=200000;
    for(i=len-1;i>=0;i--)
    {
        switch (s[i])
        {
        case '0':
        {
            s[i]='1';
            int pos1=s.rfind('0');
            int pos2=s.rfind('5');
            int pos=max(pos1,pos2);
            s[i]='0';
            if(s[pos]=='5')
            {
                if(pos<i)
                {
                    int t=len-2-pos+len-1-i;
                    res=min(res,t);
                }else
                {
                    pos--;
                    int t=len-1-i+len-2-pos;
                    res=min(res,t);
                }
            }else
            {
                int t=len-2-pos+len-1-i;
                res=min(res,t);
            }
            break;
        }
        case '2':
        {

            int fix=0;
            int pos=s.rfind('5');
            if(pos==string::npos)
            {
                break;
            }
            string temp=s;
            int t=i;
            if(pos>t)
            {
                s.erase(pos,1);
                s+='5';
                if(t==0)
                {
                    int cnt=0;
                    int k=1;
                    while(s[t+k]=='0')
                    {
                        cnt++;
                        k++;
                    }
                    if(s.size()-2==cnt&&cnt!=0)
                        break;
                    else
                    {
                        fix=cnt;
                    }
                }
            }else
            {
                s.erase(t,1);
                s+='2';
                if(pos==0)
                {
                    int cnt=0;
                    int k=1;
                    while(s[pos+k]=='0')
                    {
                        cnt++;
                        k++;
                    }
                    if(s.size()-2==cnt&&cnt!=0)
                        break;
                    else
                    {
                        fix=cnt;
                    }
                }
                fix++;
            }
            s=temp;
            int tt=len-1-pos+len-2-t+fix;
            res=min(res,tt);
            break;
        }
        case '7':
        {

            int pos=s.rfind('5');
            int fix=0;
            if(pos==string::npos)
                break;
            string temp=s;
            int t=i;
            if(pos>t)
            {
                s.erase(pos,1);
                s+='5';
                if(t==0)
                {
                    int cnt=0;
                    int k=1;
                    while(s[t+k]=='0')
                    {
                        cnt++;
                        k++;
                    }
                    if(s.size()-2==cnt&&cnt!=0)
                        break;
                    else
                    {
                        fix=cnt;
                    }
                }
            }else
            {
                s.erase(t,1);
                s+='7';
                if(pos==0)
                {
                    int cnt=0;
                    int k=1;
                    while(s[pos+k]=='0')
                    {
                        cnt++;
                        k++;
                    }
                    if(s.size()-2==cnt&&cnt!=0)
                        break;
                    else
                    {
                        fix=cnt;
                    }
                }
                fix++;
            }
            s=temp;
            int tt=len-1-pos+len-2-t+fix;
            res=min(res,tt);
            break;
        }
        }
    }
    cout<<res<<endl;
    return 0;
}
