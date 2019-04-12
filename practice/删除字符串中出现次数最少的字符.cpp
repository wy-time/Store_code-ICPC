#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef struct
{
	char a;
	int cnt;
}st;
bool cmp(st a,st b);
int main ()
{
	st info[30];
	string s;
	int i;
	while(getline(cin,s))
	{
		for(i=0;i<26;i++)
		{
			info[i].a='a'+i;
			info[i].cnt=0;
		}
		int len=s.size();
		for(i=0;i<len;i++)
		{
			info[s[i]-'a'].cnt++;
		}
		sort(info,info+26,cmp);
		int cntt=0;
		for(i=0;i<26;i++)
		{
			if(info[i].cnt!=0)
			{
				if(cntt!=0)
				{
					if(info[i].cnt!=info[i-1].cnt)
						break;
					else
					{
						int len=s.size();
						for(int j=0;j<len;j++)
						{
							len=s.size();
							if(s[j]==info[i].a)
							{
								s.erase(j,1);
								j--;
							}
						}
					}
				}else
				{
					cntt++;
					int len=s.size();
					for(int j=0;j<len;j++)
					{
						len=s.size();
						if(s[j]==info[i].a)
						{
							s.erase(j,1);
							j--;
						}
					}
				}
			}
		
		}
		cout<<s<<endl;
	}
	return 0;
}
bool cmp(st a,st b)
{
	return a.cnt<b.cnt;
}
