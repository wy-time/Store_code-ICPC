#include<iostream>
#include<string>
#include<cctype>
#include<cstring>
using namespace std;
int main ()
{
	string s;
	bool type[4]={false};
	while(getline(cin,s))
	{
		int right=0;
		int i;
		memset(type,false,sizeof(type));
		int len=s.size();
		if(len>8)
		{
			for(i=0;i<len;i++)
			{
				if(right>=3)
					break;
				if(isdigit(s[i]))
				{
					if(!type[0])
					{
						right++;
						type[0]=true;
					}
				}else if(isupper(s[i]))
				{
					if(!type[1])
					{
						right++;
						type[1]=true;
					}
				}else if(islower(s[i]))
				{
					if(!type[2])
					{
						right++;
						type[2]=true;
					}
				}else if((isspace(s[i])||ispunct(s[i]))&&!type[3])
				{
					right++;
					type[3]=true;
				}
			}
			if(right>=3)
			{
				int i,j;
				bool flag=false;
				int len=s.size();
				for(i=0;i<len-3;i++)
				{
					string b=s.substr(i,3);
					if(s.find(b,i+2)!=string::npos)
					{
						flag=true;
						break;
					}
				}
				if(flag)
					cout<<"NG"<<endl;
				else
					cout<<"OK"<<endl;
			}else
			{
				cout<<"NG"<<endl;
			}
		}else
		{
			cout<<"NG"<<endl;
		}
	}
	return 0;
}
