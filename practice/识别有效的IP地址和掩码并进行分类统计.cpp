#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<string>
using namespace std;
int slove(int *add,int model);
int main ()
{
	int ans[7]={0};
	char s[40];
	while(~scanf("%s",s))
	{
		int len=strlen(s);
		s[len]='.';
		s[len+1]='\0';
		len++;
		int i;
		int beg=0;
		int model=1;
		int cnt=0;
		//int k=1;//控制~变量 
		int add[4]={-1,-1,-1,-1};
		int temp1=-1;//储存ip类型的中间变量
		bool is0_127=false;
		int temp2=-1;
		for(i=0;i<=len;i++)
		{
			if(/*s[i-k]=='~'||*/cnt==4)
			{
				//k=0;
				//i--;
				int t=slove(add,model);
				if(model==1)
				{
					if(add[0]==127||add[0]==0)
						is0_127=true;
					temp1=t;
					if(t!=5)
					{
						if(add[0]==10||(add[0]==172&&add[1]>=16&&add[1]<=31)||(add[0]==192&&add[1]==168))
						{
							temp2=6;
						}
					}else
					{
						ans[t]++;
						break;
					}
				}else if(t==5)
				{
					ans[t]++;
				}else 
				{
					if(!is0_127)
					{
						ans[temp1]++;
						if(temp2!=-1)
							ans[temp2]++;
					}
				}
				if(model==2)
					break;
				model=2;
				beg=i;
				cnt=0;
				memset(add,-1,sizeof(add));
			}
			else if(s[i]=='.'||s[i]=='~')
			{
				//char temp=s[i];
				s[i]='\0';
				if(!isdigit(s[beg]))
				{
					ans[5]++;
					memset(add,-1,sizeof(add));
					break;
				}
				add[cnt]=atoi(&s[beg]);
				beg=i+1;
				cnt++;
				//if(temp=='~')
				//	s[i]='~';
			}
		}
	}
	int i;
	for(i=0;i<6;i++)
	{
		printf("%d ",ans[i]);
	}
	printf("%d",ans[i]);
	return 0;
}
int slove(int *add,int model)
{
	for(int i=0;i<4;i++)
	{
		if(add[i]>255||add[i]<0)
			return 5;//错误ip 或掩码 
	}
	if(model==1)
	{
		if(add[0]<=126)
			return 0;
		else if(add[0]<=191)
			return 1;
		else if(add[0]<=223)
			return 2;
		else if(add[0]<=239)
			return 3;
		else return 4;
	}else
	{
		if(add[3]==255)
			return 5;
		string s="00000000000000000000000000000000";
		int i;
		for(i=0;i<4;i++)
		{
			int t=add[i];
			int cnt=8*(i+1)-1;
			while(t)
			{
				if(t&1)
					s[cnt--]='1';
				else
					s[cnt--]='0';
				t>>=1;
			}
		}
		int temp;
		if(s.find("01")!=string::npos)
			return 5;
		if((temp=s.find("10"))!=string::npos)
		{
			if(s.find("10",temp+1)!=string::npos)
				return 5;
		}
	}
	return 100;
}
