#include<iostream>
#include<string>
#include<map>
#include<cstdio>
#include<queue>
using namespace std;
typedef map<string ,int>map1;
int main ()
{
	string s="";
	queue<string> qu;
	map1 ma;
	while(getline(cin,s))
	{
	
		int pos=-1;
		pos=s.rfind('\\');
		if(pos!=string::npos)
		{
			s=s.substr(pos+1);
		}
		bool first=true;
		int i=0;
		bool is=false;
		for(i=0;i<s.size();i++)
		{
			if(s[i]==' ')
			{
				if(first)
					first=false;
				else
				{
					while(s[i]==' ')
					{
						s.erase(i,1);
						is=true;
					}
				}
			}else if(!first)
			{
				i-=1;
				break;
			}
			if(is)
				break;
		}
		if(i-1>15)
		{
			s=s.substr(i-1-15);
		}
		if(ma.count(s)!=0)
		{
			ma[s]++;
		}else
		{
			ma.insert(make_pair(s,1));
			qu.push(s);
			if(qu.size()>8)
			{
				string temp=qu.front();
				qu.pop();
			}
		}
	}
	while(!qu.empty())
	{
		s=qu.front();
		cout<<s<<" "<<ma[s]<<endl;
		qu.pop();
	}
	return 0;
}
