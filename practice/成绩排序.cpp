#include<iostream>
#include<algorithm>
using namespace std;
typedef struct
{
	int cnt;
	char name[50];
	int score;
}st;
bool cmp1 (st a,st b);
bool cmp2 (st a,st b);
int main ()
{
	int n;
	int mode;
	
	while(cin>>n>>mode)
	{
		const int t=n;
		st info[t];
		int i;
		for(i=0;i<n;i++)
		{
			cin>>info[i].name>>info[i].score;
			info[i].cnt=i;
		}
		if(mode==0)
			sort(info,info+n,cmp1);
		else
			sort(info,info+n,cmp2);
		for(i=0;i<n;i++)
		{
			cout<<info[i].name<<" "<<info[i].score<<endl;
		}
	}
	return 0;
}
bool cmp1 (st a,st b)
{
	if(a.score!=b.score)
		return a.score>b.score;
	else
		return a.cnt<b.cnt;
}
bool cmp2 (st a,st b)
{
	if(a.score!=b.score)
		return a.score<b.score;
	else
		return a.cnt<b.cnt;
}
