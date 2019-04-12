#include<iostream>
#include<map>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	int i;	
	typedef map <int,int>map1;
	map1 ma;
	for(i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		if(ma.count(a)==0)
			ma.insert(pair<int,int>(a,b));
		else
			ma[a]+=b;
	}
	map1::iterator it;
	for(it=ma.begin();it!=ma.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}
