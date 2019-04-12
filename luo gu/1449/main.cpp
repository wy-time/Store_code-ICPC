#include <iostream>
#include<stack>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cctype>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    stack <int> ack;
    char s[1005];
    char c;
    int cnt=0;
    long long r=0;
    while(1)
    {
        c=getchar();
        if(c=='@')
            break;
        else if(c=='.')
        {
            s[cnt]='\0';
            cnt=0;
            int t=atoi(s);
            ack.push(t);
        }else if(isdigit(c))
        {
            s[cnt++]=c;
        }else
        {
            switch (c)
            {
                int a,b;
                case '+':
                    b=ack.top();
                    ack.pop();
                    a=ack.top();
                    ack.pop();
                    r=a+b;
                    ack.push(r);
                    break;
                case '-':
                    b=ack.top();
                    ack.pop();
                    a=ack.top();
                    ack.pop();
                    r=a-b;
                    ack.push(r);
                    break;
                case '*':
                    b=ack.top();
                    ack.pop();
                    a=ack.top();
                    ack.pop();
                    r=a*b;
                    ack.push(r);
                    break;
                case '/':
                    b=ack.top();
                    ack.pop();
                    a=ack.top();
                    ack.pop();
                    r=a/b;
                    ack.push(r);
                    break;
            }
        }
    }
    cout<<r;
    return 0;
}
