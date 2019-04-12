#include<iostream>
#include<map>
#include<cstring>
#include<cctype>
#include<cstdio>
using namespace std;
int main ()
{
	map <char ,int>ma;
	ma['a']=2,ma['b']=2,ma['c']=2;
	ma['d']=3,ma['e']=3,ma['f']=3;
	ma['g']=4,ma['h']=4,ma['i']=4;
	ma['j']=5,ma['k']=5,ma['l']=5;
	ma['m']=6,ma['n']=6,ma['o']=6;
	ma['p']=7,ma['q']=7,ma['r']=7,ma['s']=7;
	ma['t']=8,ma['u']=8,ma['v']=8;
	ma['w']=9,ma['x']=9,ma['y']=9,ma['z']=9;
	char s[105];
	int i;
	while(gets(s)!=NULL)
	{
		int len=strlen(s);
		for(i=0;i<len;i++)
		{
			if(isalpha(s[i]))
			{
				if(isupper(s[i]))
				{
					s[i]+='a'-'A';
					s[i]-='a';
					s[i]+=1;
					s[i]%=26;
					s[i]+='a';
				}else
					s[i]=ma[s[i]]+'0';
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
