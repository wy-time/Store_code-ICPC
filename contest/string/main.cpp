#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char ans[6][7]={"012345","6789AB","CDEFGH","IJKLMN","OPQRST","UVWXYZ"};
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    char s[505];
    int lie[6];
    int hang[6];
    int max_hang[6];
    int max_lie[6];
    while(t--)
    {
        memset(lie,0,sizeof(lie));
        memset(max_lie,0,sizeof(max_lie));
        memset(max_hang,0,sizeof(max_hang));
        memset(hang,0,sizeof(hang));
        memset(s,0,sizeof(s));
        cin>>s;
        int len=strlen(s);
        int i;
        for(i=0; i<len; i++)
        {
            if(s[i]>='0'&&s[i]<='5')
            {
                hang[0]++;
                lie[s[i]-'0']++;
                continue;
            }
            if((s[i]>='6'&&s[i]<='9')||s[i]=='A'||s[i]=='B')
            {
                hang[1]++;
                if(s[i]>='6'&&s[i]<='9')
                    lie[s[i]-'6']++;
                else
                    lie[s[i]-'A'+4]++;
                continue;
            }
            else if(s[i]>='C'&&s[i]<='H')
            {
                hang[2]++;
                lie[s[i]-'C']++;
                continue;
            }
            else if(s[i]>='I'&&s[i]<='N')
            {
                hang[3]++;
                lie[s[i]-'I']++;
                continue;
            }
            else if(s[i]>='O'&&s[i]<='T')
            {
                hang[4]++;
                lie[s[i]-'O']++;
                continue;
            }
            else if(s[i]>='U'&&s[i]<='Z')
            {
                hang[5]++;
                lie[s[i]-'U']++;
                continue;
            }
        }
        int maxh=*max_element(hang,hang+6);
        int maxl=*max_element(lie,lie+6);
        int cnt1=0;
        int cnt2=0;
        for(i=0;i<6;i++)
        {
            if(hang[i]==maxh)
            {
                max_hang[cnt1]=i;
                cnt1++;
            }
            if(lie[i]==maxl)
            {
                max_lie[cnt2]=i;
                cnt2++;
            }
        }
        for(i=0;i<cnt1;i++)
            for(int j=0;j<cnt2;j++)
            {
                cout<<ans[max_hang[i]][max_lie[j]];
            }
        cout<<endl;
    }
    return 0;
}
